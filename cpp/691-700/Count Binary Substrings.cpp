class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        char current = s[0];
        int previousCount = 0;
        int count = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == current) {
                count++;
            } else {
                current = s[i];
                previousCount = count;
                count = 1;
            }
            
            if (count <= previousCount) {
                result++;
            }
        }
        
        return result;
    }
};
