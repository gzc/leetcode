class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int best_i = 0;
        int ans = 0;
        
        for (int i = 1; i < A.size(); i++) {
            ans = max(ans, A[best_i] + A[i] + best_i - i);
            if (i + A[i] >= best_i + A[best_i]) {
                best_i = i;
            }
        }
        
        return ans;
    }
};
