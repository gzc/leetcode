class Solution {
    
    int binarySearch(vector<int> &myvec, int len, int target) {
        int i(0),j(len);
        while(i <= j && i < len) {
            int mid = (i+j) >> 1;
            if(myvec[mid] == target) return mid;
            if(myvec[mid] > target) j = mid - 1;
            else i = mid + 1;
        }
        return i;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int len(1);
        vector<int> myvec(nums.size(), 0);
        myvec[0] = nums[0];
        
        for(int i = 1;i < nums.size();i++) {
            int index = binarySearch(myvec, len, nums[i]);
            myvec[index] = nums[i];
            if(len == index) len++;
        }
        return len;
    }
};