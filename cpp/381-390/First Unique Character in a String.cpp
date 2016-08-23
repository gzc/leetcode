class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mymap;
        for (char ch : s) {
            mymap[ch]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (mymap[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
