    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 43;
            section.data(43)  = dumData; %prealloc

                    ;% rtP.frequency_voltage1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.frequency_voltage2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.frequency_voltage3
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.peakAmplitude_voltage1
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.peakAmplitude_voltage2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.peakAmplitude_voltage3
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.phaseInDegree_voltage1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.phaseInDegree_voltage2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.phaseInDegree_voltage3
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.AC_Bias
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.AC_Bias_ckphr0qig4
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.AC_Bias_eyfr42ua5t
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.StateSpace_P1_Size
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.StateSpace_P1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 14;

                    ;% rtP.StateSpace_P2_Size
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 434;

                    ;% rtP.StateSpace_P2
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 436;

                    ;% rtP.StateSpace_P3_Size
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 440;

                    ;% rtP.StateSpace_P3
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 442;

                    ;% rtP.StateSpace_P4_Size
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 449;

                    ;% rtP.StateSpace_P4
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 451;

                    ;% rtP.StateSpace_P5_Size
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 1116;

                    ;% rtP.StateSpace_P5
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 1118;

                    ;% rtP.StateSpace_P6_Size
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 1124;

                    ;% rtP.StateSpace_P6
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 1126;

                    ;% rtP.StateSpace_P7_Size
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 1129;

                    ;% rtP.StateSpace_P7
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 1131;

                    ;% rtP.StateSpace_P8_Size
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 1134;

                    ;% rtP.StateSpace_P8
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 1136;

                    ;% rtP.StateSpace_P9_Size
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 1139;

                    ;% rtP.StateSpace_P9
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 1141;

                    ;% rtP.StateSpace_P10_Size
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 1142;

                    ;% rtP.StateSpace_P10
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 1144;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 1145;

                    ;% rtP.donotdeletethisgain_Gain_hsnae3wadg
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 1146;

                    ;% rtP.Ron_Gain
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 1147;

                    ;% rtP.Ron_Gain_gisotimrpi
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 1148;

                    ;% rtP.Ron_Gain_heqalhhamz
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 1149;

                    ;% rtP.eee_Value
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 1150;

                    ;% rtP.gate_Value
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 1151;

                    ;% rtP.eee_Value_ezp1ppxfvo
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 1152;

                    ;% rtP.gate_Value_a1aaq4xqpt
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 1153;

                    ;% rtP.eee_Value_ltt5dvhgzf
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 1154;

                    ;% rtP.gate_Value_graafvp4kv
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 1155;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% rtB.cnnmnegtoe
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.otx4h10gqp
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.otltz4tihg
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.llymjhndln
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.mwvowazfto
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% rtB.ocbbvf4ln3
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtB.out0qpal0x
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 12;

                    ;% rtB.nz02ivetdb
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 13;

                    ;% rtB.cx12fc0yyz
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 14;

                    ;% rtB.a44meuoh25
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% rtB.pbtg1zqog4
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% rtB.iho2fxkxre
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% rtB.d0jsj1vn54
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% rtB.ou0uwhuegx
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% rtB.pmio0r0doy
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.awq4jr4str
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.hmqbqk2szw
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.oeybejg1lp.LoggedData
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 22;

                    ;% rtDW.dtwh04wcp2.AQHandles
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 26;

                    ;% rtDW.cyx1kfcdlz.AQHandles
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 27;

                    ;% rtDW.htww4gle3c.AQHandles
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 28;

                    ;% rtDW.gc3hjjbgux.AQHandles
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 29;

                    ;% rtDW.hybnqng5i0.LoggedData
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 30;

                    ;% rtDW.aebfs1h4gh.AQHandles
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 31;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.elswe02dqw
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.n5ib1rg2mq
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 23;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 892092326;
    targMap.checksum1 = 2020949463;
    targMap.checksum2 = 2295649570;
    targMap.checksum3 = 3430351693;

