class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string ans;
        
        while(N != 0) {
            if (N % 2 != 0) {
                ans = '1' + ans;
                N--;
            } else {
                ans = '0' + ans;
            }
            
            N = -(N/2);
        }
        
        return ans;
    }
};
