class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, ans = 0;
        
        for (char ch : S) {
            if (ch == '(') {
                left++;
            } else {
                if (left > 0) left--;
                else ans++;
            }
        }
        
        return ans + left;
    }
};
