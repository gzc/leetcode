class Solution {
public:
    bool checkValidString(string s) {
        int minLeft = 0, maxLeft = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                minLeft++;
                maxLeft++;
            } else if (ch == ')') {
                minLeft--;
                maxLeft--;
            } else {
                minLeft--;
                maxLeft++;
            }
            
            if (maxLeft < 0) {
                return false;
            }
            
            minLeft = max(0, minLeft);
        }
        
        return minLeft == 0;
    }
};
