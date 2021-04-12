class Solution {

public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (!isalpha(s[i]) && !isdigit(s[i]) && i <= j) {
                i++;
            }
            while (!isalpha(s[j]) && !isdigit(s[j]) && i <= j) {
                j--;
            }
            if (i >= j) {
                break;
            }
            if (toupper(s[i]) != toupper(s[j])) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
    
};
