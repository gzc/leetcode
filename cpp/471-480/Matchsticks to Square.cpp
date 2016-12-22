class Solution {
    
    map<int, bool> cache;
    
    int genKey(const vector<int>& nums) {
        int key = 0;
        for (int v : nums) {
            key *= 2;
            if (v > 0) key += 1;
        }
        return key;
    }
    
    bool dfs(vector<int>& nums, int sidelength, int remain, int sideidx, int currentlength) {
        int key = genKey(nums);
        if (cache.count(key) > 0) return cache[key];
        if (sideidx >= 4) return cache[key] = true;
        if (currentlength > sidelength) return cache[key]=false;
        if (remain <= 0) return cache[key]=false;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) continue;
            int temp = currentlength + nums[i];
            if (temp > sidelength) continue;
            int v = nums[i];
            nums[i] = -1;
            if (temp == sidelength) {
                bool fff = dfs(nums, sidelength, remain-1, sideidx+1, 0);
                if (fff) return true;
            } 
            else if (temp < sidelength) {
                bool fff = dfs(nums, sidelength, remain-1, sideidx, temp);
                if (fff) return true;
            }
            nums[i] = v;
        }
        
        return cache[key]=false;
    }
    
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int sidelength = sum/4;
        return dfs(nums, sidelength, nums.size(), 0, 0);
    }
};
