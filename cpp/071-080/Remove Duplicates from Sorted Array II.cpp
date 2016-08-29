class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int rear(1), n(nums.size());
        if (n <= 2) return n;
        for (int i = 2; i < n; i++)
            if (!(nums[i] == nums[rear] && nums[i] == nums[rear -1]))
                nums[++rear] = nums[i];
        return rear+1;
    }
};
