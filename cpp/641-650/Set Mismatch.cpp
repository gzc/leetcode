class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_set<int> hashset;
        int i = 0;
        while (hashset.count(nums[i]) == 0) {
            hashset.insert(nums[i]);
            i++;
        }
        result.push_back(nums[i]);
        result.push_back((1+n)*n/2 - sum + nums[i]);
        return result;
    }
};
