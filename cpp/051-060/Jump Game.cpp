class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxpos(0);

        for (int i = 0; i < nums.size(); i++) {
            if (i <= maxpos) {
                int tmp = i + nums[i];
                if(tmp >= (nums.size()-1)) return true;
                maxpos = max(tmp, maxpos);
            }
            else return false;
        }
        return false;
    }
    
};
