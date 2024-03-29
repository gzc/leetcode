class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());
        
        for (int i = 1; i < restrictions.size(); i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + restrictions[i][0] - restrictions[i-1][0]);
        }
        for (int i = restrictions.size() - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + restrictions[i+1][0] - restrictions[i][0]);
        }
        
        int res = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            int left_restriction = restrictions[i-1][1];
            int right_restriction = restrictions[i][1];
            res = max(res, max(left_restriction, right_restriction) + (restrictions[i][0] - restrictions[i-1][0] - abs(left_restriction - right_restriction)) / 2);
        }
        
        return res;
    }
};
