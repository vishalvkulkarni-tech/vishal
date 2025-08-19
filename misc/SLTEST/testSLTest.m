function testSLTest(test)
logs = test.sltest_simout.logsout;
In1 = logs.getElement('In1');
In2 = logs.getElement('In2');
Out1 = logs.getElement('Out1');
In1Data = In1.Values.Data;
In2Data = In2.Values.Data;
Out1Data = Out1.Values.Data;
expectedOut1 = In1Data + In2Data;