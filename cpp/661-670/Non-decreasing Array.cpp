class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;
        int cnt1 = 0;
        int cnt2 = 0;
        bool flag1 = true;
        bool flag2 = true;
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1]) {
                cnt1++;
                if (i!=0 && nums[i-1]>nums[i+1]) flag1=false;
            }
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                cnt2++;
                if (i < n-1 && nums[i+1] < nums[i-1]) flag2=false;
            }
        }
        
        return (flag1 && cnt1 <= 1) || (flag2 && cnt2 <= 1);
    }
};
