class Solution {
public:
    int jump(vector<int>& nums) {
        
        if (nums.size() < 2) return 0;
        
        int count(0);
        int step(0);
        int nextstep(0);
        
        for (int i = 0; i < nums.size(); i++) {
            if (i + nums[i] > nextstep) nextstep = i + nums[i];
            if (i == step && i != nums.size()-1) {
                step = nextstep;
                count++;
            }
        }
        
        return count;
    }
    
};
