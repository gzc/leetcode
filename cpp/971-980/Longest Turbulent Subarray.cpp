class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        
        int ans = 0;
        int i = 0;
        int currentFlag = 0;
        int currentLen = 1;
        
        while (i + 1 < A.size()) {
            if (A[i] < A[i+1]) {
                if (currentFlag == -1) {
                    currentLen++;
                } else if (currentFlag == 1) {
                    currentLen = 2;
                } else {
                    currentLen = 2;
                }
                currentFlag = 1;
            } else if (A[i] > A[i+1]) {
                if (currentFlag == -1) {
                    currentLen = 2;
                } else if (currentFlag == 1) {
                    currentLen++;
                } else {
                    currentLen = 2;
                }
                currentFlag = -1;
            } else {
                currentFlag = 0;
                currentLen = 1;
            }
            i++;
            ans = max(currentLen, ans); 
        }
        
        return max(currentLen, ans);
    }
};
