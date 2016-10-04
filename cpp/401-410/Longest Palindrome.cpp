class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mymap;
        for (char ch : s) {
            mymap[ch]++;
        }
        
        int res = 0;
        bool odd = false;
        for (const auto& ele : mymap) {
            if (ele.second >= 2) {
                res += ele.second % 2 == 0 ? ele.second : ele.second - 1;
            } 
            
            if (ele.second % 2 == 1) {
                odd = true;
            }
        }
        
        return odd ? res + 1 : res;
    }
};
