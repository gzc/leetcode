class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum = {0};
        for(auto x:A) sum.push_back(sum.back()+x);
        return max(help(sum, L, M), help(sum, M,L));
    }
    
    int help(const vector<int>& sum, int L, int M) {
        int maxSumL = sum[L], maxSumLM = sum[L+M];
        for(int i=L+M+1;i<sum.size();i++){
            int curSumL = sum[i-M] - sum[i-M-L];
            int curSumM = sum[i]-sum[i-M];
            maxSumL = max(maxSumL, curSumL);
            maxSumLM = max(maxSumLM, maxSumL + curSumM);
        }
        return maxSumLM;
    }
};
