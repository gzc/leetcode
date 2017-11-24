class Solution {
    
    vector<double> op(double d1, double d2) {
        vector<double> result;
        result.push_back(d1 + d2);
        result.push_back(d1 - d2);
        result.push_back(d2 - d1);
        result.push_back(d1 * d2);
        if (fabs(d2) > 1e-5) result.push_back(d1 / d2);
        if (fabs(d1) > 1e-5) result.push_back(d2 / d1);
        return result;
    }
    
    bool almost(double num) {
        return fabs(num - 24.0) < 1e-5;
    }
    
    bool dfs(vector<double> nums) {
        if (nums.size() == 2) {
            vector<double> result = op(nums[0], nums[1]);
            for (double e : result) if (almost(e)) return true;
            return false;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                vector<double> opResult = op(nums[i], nums[j]);
                for (double e : opResult) {
                    vector<double> temp;
                    for (int k = 0; k < nums.size(); k++) {
                        if (k != i && k != j) {
                            temp.push_back(nums[k]);
                        }
                    }
                    temp.push_back(e);
                    bool r = dfs(temp);
                    if (r) return true;
                }
            }
        }
        return false;
    } 
    
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> temp;
        for (int e : nums) temp.push_back(e * 1.0);
        return dfs (temp);
    }
};
