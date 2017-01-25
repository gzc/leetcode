class Solution {
private:
    void findSubsequences(vector<int> &nums, vector<int> &subsequence, set<vector<int> > &result, int index) {
        if (subsequence.size() >= 2)
            result.insert(subsequence);
        
        for (int i = index; i < nums.size(); ++i) {
            if (subsequence.size() == 0 || nums[i] >= subsequence.back()) {
                subsequence.push_back(nums[i]);
                findSubsequences(nums, subsequence, result, i + 1);
                subsequence.pop_back();
            }
        }
}

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> resultSet;
        vector<int> subsequence;
        findSubsequences(nums, subsequence, resultSet, 0);

        vector<vector<int>> result(resultSet.begin(), resultSet.end());
        return result;
    }
};
