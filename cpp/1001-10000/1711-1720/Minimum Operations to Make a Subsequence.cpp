class Solution {
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
    
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mymap;
        int base = 1;
        for (int t : target) {
            mymap[t] = base;
            base++;
        }
        
        vector<int> new_arr;
        for (int e : arr) {
            if (mymap.count(e) > 0) {
                new_arr.push_back(mymap[e]);
            }
        }
        
        return target.size() - lengthOfLIS(new_arr);
    }
};
