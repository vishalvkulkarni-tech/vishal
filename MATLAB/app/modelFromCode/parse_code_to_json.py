"""
C/C++ Code Parser for Simulink Model Generation
Parses C/C++ generated code and creates a detailed JSON structure
for model reconstruction in Simulink/Stateflow

Author: Auto-generated
Date: 2026-01-23
"""

import os
import sys
import json
import re
from pathlib import Path
from datetime import datetime
from typing import Dict, List, Any, Optional


class CodeParser:
    """Parse C/C++ code files and extract model structure"""
    
    def __init__(self, folder_path: str):
        self.folder_path = Path(folder_path)
        self.files = []
        self.functions = []
        self.constants = []
        self.defines = []
        self.inputs = []
        self.outputs = []
        self.connections = []
        self.global_vars = []
        self.detected_operation = "unknown"
        
    def find_files(self) -> List[Path]:
        """Find all C/C++ files recursively"""
        extensions = ['*.c', '*.cpp', '*.cc', '*.cxx', '*.h', '*.hpp', '*.hxx']
        files = []
        
        for ext in extensions:
            files.extend(self.folder_path.rglob(ext))
        
        print(f"Found {len(files)} files")
        return files
    
    def parse_all_files(self):
        """Parse all files in the folder"""
        file_paths = self.find_files()
        
        for file_path in file_paths:
            print(f"Parsing: {file_path.name}")
            self.parse_file(file_path)
    
    def parse_file(self, file_path: Path):
        """Parse a single file"""
        try:
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            file_info = {
                'name': file_path.stem,
                'path': str(file_path),
                'extension': file_path.suffix,
                'size': file_path.stat().st_size
            }
            
            # Extract various elements
            self._extract_defines(content, file_info)
            self._extract_constants(content, file_info)
            self._extract_functions(content, file_info)
            self._extract_inputs_outputs(content, file_info)
            self._extract_global_vars(content, file_info)
            
            # Analyze connections and operations
            self._analyze_operations(content, file_info)
            
            self.files.append(file_info)
            
        except Exception as e:
            print(f"Error parsing {file_path}: {e}")
    
    def _remove_comments(self, content: str) -> str:
        """Remove C/C++ comments"""
        # Remove single-line comments
        content = re.sub(r'//.*?$', '', content, flags=re.MULTILINE)
        # Remove multi-line comments
        content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
        return content
    
    def _extract_defines(self, content: str, file_info: Dict):
        """Extract #define constants with numeric values"""
        pattern = r'#define\s+(\w+)\s+(.+?)(?:\n|$)'
        matches = re.finditer(pattern, content)
        
        for match in matches:
            name = match.group(1)
            value = match.group(2).strip()
            
            # Skip function-like macros and non-numeric defines
            if '(' not in name and '(' not in value:
                # Try to parse as number
                try:
                    value_clean = re.sub(r'[ULFulf]+$', '', value)
                    if value_clean.startswith('0x'):
                        numeric_val = float(int(value_clean, 16))
                    else:
                        numeric_val = float(value_clean)
                    
                    define_info = {
                        'name': name,
                        'value': value,
                        'numericValue': numeric_val,
                        'file': file_info['name']
                    }
                    self.defines.append(define_info)
                    print(f"  Found define: {name} = {numeric_val}")
                except:
                    # Skip non-numeric defines
                    pass
    
    def _extract_constants(self, content: str, file_info: Dict):
        """Extract constant variable declarations with actual numeric values"""
        clean_content = self._remove_comments(content)
        
        # Pattern for const declarations
        patterns = [
            r'const\s+\w+\s+(\w+)\s*=\s*([^;]+);',
            r'\w+\s+const\s+(\w+)\s*=\s*([^;]+);',
            r'static\s+const\s+\w+\s+(\w+)\s*=\s*([^;]+);'
        ]
        
        for pattern in patterns:
            matches = re.finditer(pattern, clean_content)
            for match in matches:
                name = match.group(1)
                value_str = match.group(2).strip()
                
                # Try to extract numeric value
                try:
                    # Handle common formats: 10.0, 10, 0x10, 10UL, etc.
                    value_clean = re.sub(r'[ULFulf]+$', '', value_str)
                    if value_clean.startswith('0x'):
                        value = float(int(value_clean, 16))
                    else:
                        value = float(value_clean)
                    
                    const_info = {
                        'name': name,
                        'value': value_str,
                        'numericValue': value,
                        'file': file_info['name']
                    }
                    self.constants.append(const_info)
                    print(f"  Found constant: {name} = {value}")
                except:
                    # Keep as string if can't parse
                    const_info = {
                        'name': name,
                        'value': value_str,
                        'file': file_info['name']
                    }
                    self.constants.append(const_info)
    
    def _extract_functions(self, content: str, file_info: Dict):
        """Extract function definitions and declarations"""
        clean_content = self._remove_comments(content)
        
        # Pattern for function definitions
        pattern = r'(\w+(?:\s+\w+)?)\s+(\w+)\s*\(([^)]*)\)\s*{'
        matches = re.finditer(pattern, clean_content)
        
        for match in matches:
            return_type = match.group(1).strip()
            func_name = match.group(2)
            params = match.group(3).strip()
            
            # Skip common non-model functions
            skip_patterns = ['main', 'memcpy', 'memset', 'printf', 'sizeof']
            if any(skip in func_name.lower() for skip in skip_patterns):
                continue
            
            func_info = {
                'name': func_name,
                'returnType': return_type,
                'parameters': self._parse_parameters(params),
                'file': file_info['name'],
                'isStepFunction': 'step' in func_name.lower(),
                'isInitFunction': 'init' in func_name.lower(),
                'isTerminateFunction': 'terminate' in func_name.lower()
            }
            
            self.functions.append(func_info)
    
    def _parse_parameters(self, params_str: str) -> List[Dict]:
        """Parse function parameters"""
        if not params_str or params_str.strip() in ['void', '']:
            return []
        
        params = []
        param_list = params_str.split(',')
        
        for param in param_list:
            param = param.strip()
            if not param:
                continue
            
            # Try to extract type and name
            parts = param.split()
            if len(parts) >= 2:
                param_type = ' '.join(parts[:-1])
                param_name = parts[-1].strip('*&')
                
                params.append({
                    'type': param_type,
                    'name': param_name
                })
        
        return params
    
    def _extract_inputs_outputs(self, content: str, file_info: Dict):
        """Extract input and output signal structures"""
        clean_content = self._remove_comments(content)
        
        # Input patterns
        input_patterns = [
            r'ExtU_\w+',
            r'rtU\.\w+',
            r'_U\.\w+',
            r'U->\w+',
            r'\bIn\d+\b'
        ]
        
        # Output patterns
        output_patterns = [
            r'ExtY_\w+',
            r'rtY\.\w+',
            r'_Y\.\w+',
            r'Y->\w+',
            r'\bOut\d+\b'
        ]
        
        # Find inputs
        for pattern in input_patterns:
            matches = re.finditer(pattern, clean_content)
            for match in matches:
                signal = match.group(0)
                if not any(inp['name'] == signal for inp in self.inputs):
                    self.inputs.append({
                        'name': signal,
                        'type': 'input',
                        'file': file_info['name']
                    })
        
        # Find outputs
        for pattern in output_patterns:
            matches = re.finditer(pattern, clean_content)
            for match in matches:
                signal = match.group(0)
                if not any(out['name'] == signal for out in self.outputs):
                    self.outputs.append({
                        'name': signal,
                        'type': 'output',
                        'file': file_info['name']
                    })
    
    def _extract_global_vars(self, content: str, file_info: Dict):
        """Extract global variable declarations"""
        clean_content = self._remove_comments(content)
        lines = clean_content.split('\n')
        
        for line in lines:
            line = line.strip()
            
            # Skip empty, preprocessor, and function lines
            if not line or line.startswith('#') or '(' in line:
                continue
            
            # Look for global variable pattern
            if ';' in line and not line.startswith('typedef'):
                match = re.match(r'^(\w+(?:\s+\w+)?)\s+(\w+)\s*(?:=|;)', line)
                if match:
                    var_type = match.group(1).strip()
                    var_name = match.group(2)
                    
                    self.global_vars.append({
                        'name': var_name,
                        'type': var_type,
                        'file': file_info['name']
                    })
    
    def _analyze_operations(self, content: str, file_info: Dict):
        """Analyze code to detect operations and data flow"""
        clean_content = self._remove_comments(content)
        
        # Find step function body
        step_pattern = r'void\s+\w*step\w*\s*\([^)]*\)\s*{([^}]+)}'
        step_match = re.search(step_pattern, clean_content, re.IGNORECASE | re.DOTALL)
        
        if step_match:
            step_body = step_match.group(1)
            print(f"  Found step function in {file_info['name']}")
            self._analyze_step_function(step_body, file_info)
        
        # Fallback: analyze all assignment statements
        self._analyze_all_assignments(clean_content, file_info)
    
    def _analyze_step_function(self, step_body: str, file_info: Dict):
        """Analyze step function to detect operations"""
        lines = step_body.split('\n')
        
        for line in lines:
            line = line.strip()
            
            # Look for assignments with operations
            if '=' in line and ';' in line and '==' not in line:
                self._parse_assignment(line, file_info)
    
    def _analyze_all_assignments(self, content: str, file_info: Dict):
        """Analyze all assignments in the code"""
        lines = content.split('\n')
        
        for line in lines:
            line = line.strip()
            
            # Look for output assignments
            if '=' in line and ';' in line and '==' not in line:
                # Check if involves output
                if any(pattern in line for pattern in ['Out', 'rtY', '_Y', 'output']):
                    self._parse_assignment(line, file_info)
    
    def _parse_assignment(self, line: str, file_info: Dict):
        """Parse an assignment to detect operation and extract operands"""
        # Split on =
        parts = line.split('=', 1)
        if len(parts) < 2:
            return
        
        lhs = parts[0].strip()
        rhs = parts[1].replace(';', '').strip()
        
        # Detect operation type and extract operands
        operation = 'assignment'
        operands = []
        
        if '+' in rhs and '++' not in rhs:
            operation = 'addition'
            self.detected_operation = 'addition'
            # Extract operands
            operands = [op.strip() for op in rhs.split('+')]
            print(f"  >>> DETECTED ADDITION: {operands[0]} + {operands[1]}")
            
        elif '-' in rhs and '--' not in rhs and '->' not in rhs:
            operation = 'subtraction'
            operands = [op.strip() for op in rhs.split('-')]
            if self.detected_operation == 'unknown':
                self.detected_operation = 'subtraction'
                
        elif '*' in rhs and not rhs.startswith('*'):
            operation = 'multiplication'
            operands = [op.strip() for op in rhs.split('*')]
            if self.detected_operation == 'unknown':
                self.detected_operation = 'multiplication'
                
        elif '/' in rhs and '//' not in line:
            operation = 'division'
            operands = [op.strip() for op in rhs.split('/')]
            if self.detected_operation == 'unknown':
                self.detected_operation = 'division'
        
        connection = {
            'from': rhs,
            'to': lhs,
            'operation': operation,
            'operands': operands,
            'line': line.strip(),
            'file': file_info['name']
        }
        
        self.connections.append(connection)
    
    def generate_json(self, output_path: Optional[str] = None) -> Dict[str, Any]:
        """Generate JSON structure"""
        
        # Categorize functions
        main_functions = [f for f in self.functions if f['isStepFunction']]
        helper_functions = [f for f in self.functions if not f['isStepFunction'] 
                          and not f['isInitFunction'] and not f['isTerminateFunction']]
        
        # Identify actual model inputs vs constants
        model_constants = [c for c in self.constants if 'numericValue' in c]
        model_constants.extend([d for d in self.defines if 'numericValue' in d])
        
        # Extract operands from connections to identify what's actually used
        used_operands = []
        for conn in self.connections:
            if 'operands' in conn and conn['operands']:
                used_operands.extend(conn['operands'])
        
        json_data = {
            'timestamp': datetime.now().isoformat(),
            'source_folder': str(self.folder_path),
            'summary': {
                'totalFiles': len(self.files),
                'totalFunctions': len(self.functions),
                'mainFunctions': len(main_functions),
                'helperFunctions': len(helper_functions),
                'constants': len(self.constants),
                'defines': len(self.defines),
                'modelConstants': len(model_constants),
                'inputs': len(self.inputs),
                'outputs': len(self.outputs),
                'connections': len(self.connections),
                'globalVariables': len(self.global_vars),
                'detectedOperation': self.detected_operation
            },
            'modelInputs': {
                'constants': model_constants,
                'usedOperands': list(set(used_operands))
            },
            'relevantConstants': model_constants,
            'allConstants': self.constants,
            'allDefines': self.defines,
            'detectedInputs': self.inputs,
            'detectedOutputs': self.outputs,
            'mainFunctions': main_functions,
            'connections': self.connections,
            'modelStructure': {
                'hasStateMachine': self._detect_state_machine(),
                'operationType': self.detected_operation,
                'recommendedModelType': self._recommend_model_type()
            }
        }
        
        # Save to file if path provided
        if output_path:
            with open(output_path, 'w', encoding='utf-8') as f:
                json.dump(json_data, f, indent=2)
            print(f"\nJSON saved to: {output_path}")
            print(f"File size: {os.path.getsize(output_path) / 1024:.2f} KB")
        
        return json_data
    
    def _detect_state_machine(self) -> bool:
        """Detect if code contains state machine patterns"""
        for func in self.functions:
            if any(keyword in func['name'].lower() for keyword in ['state', 'fsm', 'sm_']):
                return True
        return False
    
    def _recommend_model_type(self) -> str:
        """Recommend Simulink or Stateflow model type"""
        if self._detect_state_machine():
            return 'stateflow' if len(self.functions) < 5 else 'combined'
        return 'simulink'
    
    def print_summary(self):
        """Print analysis summary"""
        print("\n" + "="*60)
        print("PARSING SUMMARY")
        print("="*60)
        print(f"Files analyzed: {len(self.files)}")
        print(f"Functions found: {len(self.functions)}")
        print(f"  - Step functions: {len([f for f in self.functions if f['isStepFunction']])}")
        print(f"Constants/Defines: {len(self.constants) + len(self.defines)}")
        print(f"Inputs detected: {len(self.inputs)}")
        print(f"Outputs detected: {len(self.outputs)}")
        print(f"Connections found: {len(self.connections)}")
        print(f"Global variables: {len(self.global_vars)}")
        print(f"\n>>> DETECTED OPERATION: {self.detected_operation.upper()} <<<")
        print("="*60)


def main():
    """Main entry point"""
    if len(sys.argv) > 1:
        folder_path = sys.argv[1]
    else:
        # Interactive mode
        print("C/C++ Code Parser for Simulink Model Generation")
        print("-" * 50)
        folder_path = input("Enter folder path containing C/C++ files: ").strip('"')
    
    if not os.path.exists(folder_path):
        print(f"Error: Folder not found: {folder_path}")
        sys.exit(1)
    
    # Parse code
    parser = CodeParser(folder_path)
    parser.parse_all_files()
    
    # Generate JSON
    output_json = os.path.join(os.path.dirname(__file__), 'GeneratedModels', 'code_analysis.json')
    os.makedirs(os.path.dirname(output_json), exist_ok=True)
    
    parser.generate_json(output_json)
    parser.print_summary()
    
    print(f"\nNext step: Run the MATLAB script to generate Simulink model from the JSON")
    return 0


if __name__ == '__main__':
    sys.exit(main())
