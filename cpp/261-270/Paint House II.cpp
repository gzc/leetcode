class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        vector<vector<int> > v(2, vector<int>(costs[0].size(), 0));
        for(int i = 0;i < costs[0].size();i++) v[0][i] = costs[0][i];
        int k = 0;
        
        for(int i = 1;i < costs.size();i++)
        {
            int minimum1 = min(v[k][0], v[k][1]);
            int minimum2 = max(v[k][0], v[k][1]);
            for(int j = 2;j < costs[0].size();j++)
            {
                if(v[k][j] < minimum1) {
                    minimum2 = minimum1;
                    minimum1 = v[k][j];
                } else if(v[k][j] >= minimum1 && v[k][j] < minimum2) {
                    minimum2 = v[k][j];
                }
            }
            
            k = (k+1)%2;
            
            for(int j = 0;j < costs[0].size();j++)
            {
                if(minimum1 != v[(k+1)%2][j]) v[k][j] = minimum1 + costs[i][j];
                else v[k][j] = minimum2 + costs[i][j];
            }
            
        }
        
        return *min_element(v[k].begin(), v[k].end());
    }
};