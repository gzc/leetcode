class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        bool flag = false;
        
        if (numerator > 0 && denominator < 0) {
            flag = true;
        } else if (numerator < 0 && denominator > 0) {
            flag = true;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        int64_t remain = numerator % denominator;
        int64_t d = numerator/denominator;
        string result = to_string(d);
        if (flag) result = "-"+result;
        if (remain == 0)
            return result;
        
        unordered_map<int, int>p;
        string small = "";
        int index = 0;
        
        while (remain > 0) {
            p[remain] = index;
            int64_t tmp = remain*10;
            int64_t digit = tmp/denominator;
            remain = tmp%denominator;
            small += to_string(digit);
            
            if (p.count(remain) > 0) {
                small.insert(p[remain], "(");
                small += ")";
                break;
            }
            index++;
        }

        return result+"."+small;
    }
};
