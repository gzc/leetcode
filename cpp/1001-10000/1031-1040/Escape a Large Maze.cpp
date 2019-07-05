class Solution {
    
    bool find = false;
    
    pair<int, int> tmp[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool isEscapePossibleInternal(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int, int>> visited;
        for (const vector<int>& b : blocked) {
            visited.insert({b[0], b[1]});
        }
        
        stack<pair<int, int>> mystack;
        mystack.push({source[0], source[1]});
        visited.insert({source[0], source[1]});
        
        while (!mystack.empty()) {
            pair<int, int> ele = mystack.top();
            mystack.pop();
            if (ele.first == target[0] && ele.second == target[1]) { find = true; return true; }
            int dis = abs(ele.first - source[0]) + abs(ele.second - source[1]);
            if (dis > blocked.size()) return true;
            
            for (int k = 0; k < 4; k++) {
                int n_i = ele.first + tmp[k].first;
                int n_j = ele.second + tmp[k].second;
                if (n_i < 0 || n_j < 0 || n_i >= 1e6 || n_j >= 1e6) continue;
                if (visited.count({n_i, n_j}) > 0) continue;
                
                visited.insert({n_i, n_j});
                mystack.push({n_i, n_j});
            }
        }
        
        return false;
    }
    
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (!isEscapePossibleInternal(blocked, source, target)) return false;
        if (find) return true;
        return isEscapePossibleInternal(blocked, target, source);
    }
};
