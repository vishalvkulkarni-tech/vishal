classdef EleNW
    % Passive component Class

    properties
        topo_el             string          % topology string
        n_par
        n_ser
    end

    properties (Dependent)
        topo_el_n           double          % number of components
        topo_el_pos         string          % name or part number of R/L/C n*1 array
        topo_el_imp                         % n*n array of R/L/C impedence
    end

    methods (Access = public)
        function output1 = EleNW(varargin)
            % initialize Passive component
            input1 = "topo_el";
            for k = 1:nargin
                output1.(input1{k}) = varargin{k};
            end
        end
    end

    methods
        function obj = set.topo_el(obj, value)
            obj.topo_el = value;
%             obj = obj.update_topo_el_n(obj);
%             obj = obj.update_topo_el_pos(obj);
%             obj = obj.update_topo_el_imp(obj);
        end
    end
    %%
    methods
        function topo_el_n = get.topo_el_n(obj)
            topo_el_n = numel(strfind(obj.topo_el, 'R')) + ...
                numel(strfind(obj.topo_el, 'L')) + ...
                numel(strfind(obj.topo_el, 'C'));
        end
        %%
        function topo_el_imp = get.topo_el_imp(obj)
            topo_el_imp_local = struct('topo_el_item', {}, 'topo_el_name', {}, 'R', {}, 'L', {}, 'C', {}, 'nParallel', {}, 'nSeries', {});
            RLCInd = strfind(upper(obj.topo_el), ("R" | "L" | "C"));
            resiCnt = 1;
            capaCnt = 1;
            chokCnt = 1;
            topoChar = char(obj.topo_el);
            for cmpntCnt = 1:length(RLCInd)
                component = upper(topoChar(RLCInd(cmpntCnt)));
                switch component
                    case "R"
                        if isempty(obj.Resi)
                            continue;
                        end
                        localObj = obj.Resi(resiCnt);
                        resiCnt = resiCnt + 1;
                    case "L"
                        if isempty(obj.Chok)
                            continue;
                        end
                        localObj = obj.Chok(chokCnt);
                        chokCnt = chokCnt + 1;
                    case "C"
                        if isempty(obj.Capa)
                            continue;
                        end
                        localObj = obj.Capa(capaCnt);
                        capaCnt = capaCnt + 1;
                end
                topo_el_imp_local(cmpntCnt).topo_el_item = component;
                topo_el_imp_local(cmpntCnt).topo_el_name = localObj.name;
                topo_el_imp_local(cmpntCnt).nParallel = obj.n_par(cmpntCnt);
                topo_el_imp_local(cmpntCnt).nSeries = obj.n_ser(cmpntCnt);
                if isprop(localObj, 'R')
                    topo_el_imp_local(cmpntCnt).R = (localObj.R * obj.n_ser(cmpntCnt))/obj.n_par(cmpntCnt);
                else
                    topo_el_imp_local(cmpntCnt).R = 0;
                end
                if isprop(localObj, 'L')
                    topo_el_imp_local(cmpntCnt).L = (localObj.L * obj.n_ser(cmpntCnt))/obj.n_par(cmpntCnt);
                else
                    topo_el_imp_local(cmpntCnt).L = 0;
                end
                if isprop(localObj, 'C')
                    topo_el_imp_local(cmpntCnt).C = (localObj.C/obj.n_ser(cmpntCnt))*obj.n_par(cmpntCnt);
                else
                    topo_el_imp_local(cmpntCnt).C = 0;
                end
            end
            topo_el_imp = topo_el_imp_local;
        end
        %%
        function topo_el_pos = get.topo_el_pos(obj)
            RLCInd = strfind(upper(obj.topo_el), ("R" | "L" | "C"));
            resiCnt = 1;
            capaCnt = 1;
            chokCnt = 1;
            topoChar = char(obj.topo_el);
            topo_el_pos = [];
            for cmpntCnt = 1:length(RLCInd)
                component = upper(topoChar(RLCInd(cmpntCnt)));
                switch component
                    case "R"
                        if isempty(obj.Resi)
                            continue;
                        end
                        name = obj.Resi.name;
                        resiCnt = resiCnt + 1;
                    case "L"
                        if isempty(obj.Chok)
                            continue;
                        end
                        name = obj.Chok.name;
                        chokCnt = chokCnt + 1;
                    case "C"
                        if isempty(obj.Capa)
                            continue;
                        end
                        name = obj.Capa.name;
                        capaCnt = capaCnt + 1;
                end
                topo_el_pos = [topo_el_pos name];
            end
        end
    end
end