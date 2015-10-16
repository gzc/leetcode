class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        int i1(costs[0][0]), i2(costs[0][1]), i3(costs[0][2]);
        
        for(int i = 1;i < costs.size();i++)
        {
            int o1(i1),o2(i2),o3(i3);
            i1 = min(o2,o3) + costs[i][0];
            i2 = min(o1,o3) + costs[i][1];
            i3 = min(o1,o2) + costs[i][2];
        }
        
        int result = min(i1,i2);
        result = min(result, i3);
        return result;
    }
};