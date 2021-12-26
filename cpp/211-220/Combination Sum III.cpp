class Solution {
    
    void help(vector<int>& now, int index, int num, int target, vector<vector<int>>& results) {
        if (num == 0) {
            return;
        }
        for (int i = index; i <= 9; i++) {
            if (i < target) {
                now.push_back(i);
                help(now, i+1, num-1, target-i, results);
                now.pop_back();
            } else if (i == target && num == 1) {
                now.push_back(i);
                results.push_back(now);
                now.pop_back();
            }
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int>tmp;
        help(tmp, 1, k, n, results);
        
        return results;
    }
};
