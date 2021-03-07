class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return (abs(goal - sum) + limit - 1) / limit;
    }
};
