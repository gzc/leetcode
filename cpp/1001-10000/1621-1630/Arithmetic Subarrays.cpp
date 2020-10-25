class Solution {
    
    bool check(const vector<int>& vec) {
        for (int i = 2; i < vec.size(); i++) {
            if ((vec[i] - vec[i-1]) != (vec[i-1] - vec[i-2])) return false;
        }
        return true;
    }
    
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        
        int m = l.size();
        
        for (int i = 0; i < m; i++) {
            int a1 = l[i];
            int a2 = r[i];
            vector<int> tmp(nums.begin()+a1, nums.begin()+a2+1);
            
            sort(tmp.begin(), tmp.end());
            ans.push_back(check(tmp));
        }
        
        return ans;
    }
};
