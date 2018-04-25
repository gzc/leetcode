class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        map<int, long> mymap;
        sort(A.begin(), A.end());
        unordered_set<int> myset(A.begin(), A.end());
        
        int mod = 1000000007;
        long ans = 0;
        
        for (int i = 0; i < A.size(); i++) {
            long temp = 1;
            for (int j = 0; j < i; j++) {
                if (A[i] % A[j] == 0) {
                    int divide = A[i] / A[j];
                    if (myset.count(divide) > 0) {
                        long left = mymap[A[j]];
                        long right = mymap[divide];
                        temp += (left*right) % mod;
                        temp = temp % mod;
                    }
                }
            }
            mymap[A[i]] = temp;
            ans += mymap[A[i]];
            ans %= mod;
        }
    
        return ans;
    }
};
