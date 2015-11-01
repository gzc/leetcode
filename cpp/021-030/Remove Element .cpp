class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first(0);
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] != val)
                swap(nums[i], nums[first++]);
        }
        return first;
    }
};
