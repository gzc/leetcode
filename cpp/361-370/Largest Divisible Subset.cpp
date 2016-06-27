class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> res;
        if(nums.size() == 0) return res;
        
        sort(nums.begin(), nums.end());
        
        vector<int> previous(nums.size(), -1);
        vector<int> size(nums.size(), 1);
        
        int result_idx(0);
        int max_size(0);
        
        for(int i = 1;i < nums.size();i++) {
            
            int idx(-1);
            int msize(1);
            
            for(int j = 0;j < i;j++) {
                
                if(nums[i] % nums[j] == 0) {
                    if(size[j] + 1 > msize) {
                        msize = size[j]+1;
                        idx = j;
                    }
                }
                
            }
            
            previous[i] = idx;
            size[i] = msize;
            
            if(msize > max_size) {
                result_idx = i;
                max_size = msize;
            }
        }
        
        while(result_idx >= 0) {
            res.push_back(nums[result_idx]);
            result_idx = previous[result_idx];
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
