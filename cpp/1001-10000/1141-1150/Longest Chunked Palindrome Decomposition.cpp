class Solution {
public:
    int longestDecomposition(string text) {
        if (text.length() <= 1) return text.length();
        int i_start = 0;
        
        int i_end = i_start + 1;
        int j_start = text.length() - 1;
        
        while (true) {
            if (j_start < i_end) {
                return 1;
            }
            
            string str1 = text.substr(i_start, i_end - i_start);
            string str2 = text.substr(j_start);
            
            if (str1 == str2) {
                int len = text.length() - 2 * (i_end - i_start);
                return 2 + longestDecomposition(text.substr(i_end, len));
            }
            
            i_end++;
            j_start--;
        }
        
        return 1;
    }
};
