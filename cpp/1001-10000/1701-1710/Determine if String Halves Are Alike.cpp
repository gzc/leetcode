class Solution {
public:
    bool halvesAreAlike(string s) {
        map<char, int> mymap;
        
        int n = s.length()/2;
        
        for (int i = 0; i < n; i++) {
            mymap[tolower(s[i])]++;
        }
        
        for (int i = n; i < s.length(); i++) {
            mymap[tolower(s[i])]--;
        }
        
        return (mymap['a'] + mymap['e'] + mymap['i'] + mymap['o'] + mymap['u']) == 0;
    }
};
