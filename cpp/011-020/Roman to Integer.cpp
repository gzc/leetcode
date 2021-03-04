class Solution {
public:
    
    int romanToInt(string s) {
        map<char, int> table { 
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        for (int i = 0;i < s.length();i++) {
            if (i < s.length()-1 && table[s[i]] < table[s[i+1]] ) {
                result -= table[s[i]];
            } else {
                result += table[s[i]];
            }
        }
        
        return result;
    }
    
};
