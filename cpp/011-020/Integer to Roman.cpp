class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mymap{
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
            {100, "C"}, {500, "D"}, {1000, "M"},
            {4, "IV"}, {9, "IX"},
            {40, "XL"}, {90, "XC"},
            {400, "CD"}, {900, "CM"}
        };
        
        stringstream ss;
        for (auto it = mymap.rbegin(); it != mymap.rend(); it++) {
            int key = it->first;
            const string& code = it->second;
            while (num >= key) {
                num -= key;
                ss << code;
            }
        }
        
        return ss.str();
    }
};
