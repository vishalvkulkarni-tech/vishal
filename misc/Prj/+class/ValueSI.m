classdef ValueSI
    properties
        prefix
        unit
    end
    properties (Dependent)
        data
    end
    properties
        value
    end

    methods
        function data = get.data(obj)
            switch obj.prefix
                case "n"
                    denom = 10^-9;
                case "u"
                    denom = 10^-6;
                case "m"
                    denom = 10^-3;
                case "k"
                    denom = 10^3;
                case "M"
                    denom = 10^6;
                case "G"
                    denom = 10^9;
                otherwise % SI
                    denom = 1;
            end
            data = obj.value*denom;
        end
    end
end