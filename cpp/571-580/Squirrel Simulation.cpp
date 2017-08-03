class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int save = INT_MAX;
        for (const auto& nut : nuts) {
            int d = dis(tree[0], nut[0], tree[1], nut[1]);
            sum += d*2;
            int d2 = dis(squirrel[0], nut[0], squirrel[1], nut[1]);
            save = min(save, d2 - d);
        }
        return sum + save;
    }
    
    int dis(int a1, int b1, int a2, int b2) {
        return abs(a1 - b1) + abs(a2 - b2);
    }
};
