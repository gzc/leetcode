class Solution {

    bool isKPartitionPossibleRec(const vector<int>& nums, int subsetSum, bool taken[],
                       int subset, int K, int N, int limitIdx) {
        if (subsetSum == subset) {
            if (K == 2) return true;
            return isKPartitionPossibleRec(nums, 0, taken, subset, K - 1, N, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                bool nxt = isKPartitionPossibleRec(nums, subsetSum + nums[i], taken, subset, K, N, i - 1);
                taken[i] = false;
                if (nxt) return true;
            }
        }
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        if (k == 1) return true;
        if (N < k) return false;

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int subset = sum / k;
        bool taken[N];
        fill(taken, taken + N, false);
        taken[N - 1] = true;

        //  call recursive method to check K-substitution condition
        return isKPartitionPossibleRec(nums, nums[N-1], taken, subset, k, N, N - 1);
    }
};
