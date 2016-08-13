class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mynums(nums.begin(), nums.end());
        int longest(1);
        for (int num : nums) {
            int tmp(1);
            if (mynums.find(num-1) == mynums.end()) {
                while (mynums.find(++num) != mynums.end()) { 
                    tmp++;
                }
                longest = max(longest, tmp);
            }
        }
        return longest;
    }
};
