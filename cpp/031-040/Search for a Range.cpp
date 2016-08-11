class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int>::iterator low,up;
        low =std::lower_bound (nums.begin(), nums.end(), target);
        up = std::upper_bound (nums.begin(), nums.end(), target); 
        vector<int> result;
        if (low == up) {
            result.push_back(-1);
            result.push_back(-1);
        } else {
            result.push_back(low - nums.begin());
            result.push_back(up - nums.begin() - 1);
        }
        return result;
    }
};
