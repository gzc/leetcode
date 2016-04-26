class Solution {
public:
    string reverseString(string s) {
        for(int i = 0;i < s.length()/2;i++) {
            swap(s[i], s[s.length()-1-i]);
        }
        return s;
    }
};