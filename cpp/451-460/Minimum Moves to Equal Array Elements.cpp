class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0) - nums.size() * *min_element(begin(nums), end(nums));
    }
};
