class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> mymap(256, 0);
        vector<int> stats(256, 0);
        
        int count = s1.length();
        for (char ch : s1) {
            mymap[ch]++;
        }
        
        for (int i = 0; i < s1.length(); i++) {
            char ch = s2[i];
            if(mymap[ch] > 0) {
                stats[ch]++;
                if (stats[ch] <= mymap[ch]) {
                    count--;
                }
            }
        }
        
        if (count == 0) return true;
        
        for (int i = s1.length(); i < s2.length(); i++) {
            char oldChar = s2[i - s1.length()];
            char newChar = s2[i];
            if (oldChar == newChar) continue;
            if (mymap[oldChar] > 0) {
                stats[oldChar]--;
                if (stats[oldChar] < mymap[oldChar] && stats[oldChar] >= 0) {
                    count++;
                }
            }
            if (mymap[newChar] > 0) {
                stats[newChar]++;
                if (stats[newChar] <= mymap[newChar] && stats[newChar] >= 0) {
                    count--;
                }
            }
            if (count == 0) return true;
        }
        
        return false;
    }
};
