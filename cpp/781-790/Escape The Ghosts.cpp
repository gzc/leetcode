class Solution {
    
    int dis(int x, int y) {
        return abs(x) + abs(y);
    }
    
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int temp = dis(target[0], target[1]); 
        for (const auto& ghost : ghosts) {
            if (dis(target[0] - ghost[0], target[1] - ghost[1]) <= temp) return false;
        }
        return true;
    }
};
