class Solution {
    
    string helper(string str) {
        string dec_to_hex = "0123456789abcdef";

        int dec_num = stoi(str, nullptr, 16);
        int q = (dec_num+8) / 17;
        string res(2, dec_to_hex[q]);
        return res;
    }
    
public:
    string similarRGB(string color) {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }
};
