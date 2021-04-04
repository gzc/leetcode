class Solution {
public:
    string truncateSentence(string s, int k) {
        int space_idx = -1;
        int num_spaces = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                num_spaces++;
            }
            if (num_spaces == k) {
                space_idx = i;
                break;
            }
        }
        
        if (space_idx < 0) {
            return s;
        } else {
            return s.substr(0, space_idx);
        }
    }
};
