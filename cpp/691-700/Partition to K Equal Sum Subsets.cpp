class Solution {

    bool isKPartitionPossibleRec(const vector<int>& nums, int subsetSum, bool taken[], int target, int K, int limitIdx) {
        if (subsetSum == target) {
            if (K == 2) return true;
            return isKPartitionPossibleRec(nums, 0, taken, target, K - 1, 0);
        }

        for (int i = limitIdx; i < nums.size(); i++) {
            if (taken[i]) continue;
            int tmp = subsetSum + nums[i];

            if (tmp <= target) {
                taken[i] = true;
                bool nxt = isKPartitionPossibleRec(nums, subsetSum + nums[i], taken, target, K, i + 1);
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
        taken[0] = true;

        //  call recursive method to check K-substitution condition
        return isKPartitionPossibleRec(nums, nums[0], taken, subset, k, 0);
    }
};
