class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        vector<char> toHexChar = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string result;
        while (num != 0 && result.size()<8){
            result = toHexChar[num&15] + result;
            num = num >> 4;
        }
        return result;
    }
};
