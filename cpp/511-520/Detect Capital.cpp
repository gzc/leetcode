class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isUpper = isupper(word[0]);
        
        if (isUpper) {
            isUpper = isupper(word[1]);
            for (int i = 2; i < word.length(); i++) {
                if (islower(word[i])) {
                    if (isUpper) return false;
                } else {
                    if (!isUpper) return false;
                }
            }
        } else {
            for (int i = 1; i < word.length(); i++) {
                if (!islower(word[i])) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
