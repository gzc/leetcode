class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        map<int, int> startIndex, count;
        int len = nums.size(), fre = 0;
        for (int i = 0; i < nums.size() ;i++) {
            if (startIndex.count(nums[i]) == 0) startIndex[nums[i]] = i;
            count[nums[i]]++;
            if (count[nums[i]] == fre) {
                len = min(i - startIndex[nums[i]] + 1, len);
            }
            if (count[nums[i]] > fre) {
                len = i - startIndex[nums[i]] + 1;
                fre = count[nums[i]];
            }
        }
        return len;
    }
};
