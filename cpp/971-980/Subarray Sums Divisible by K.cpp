class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> record(K+1, 0);
        record[0] = 1;
        
        int sum = 0;
        int ans = 0;
        for (int e : A) {
            sum += e;
            // Make it a positive number to avoid bad mod.
            if (sum < 0) sum += (-1*sum / K) * K + K;
            int target = sum % K;
            // You can also remove following line.
            sum = target;
            ans += record[target];
            record[target]++;
        }
        return ans;
    }
};
