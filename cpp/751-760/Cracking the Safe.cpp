class Solution {
    
    bool dfs(int total, string& ans, int n, int k, bool* nodes) {
        if (total == 0) return true;
        ans += '0';
        for (int d = 0; d < k; d++) {
            ans.back() = d + '0';
            int t = stoi(ans.substr(ans.size()-n, n));
            if (!nodes[t]) {
                nodes[t] = true;
                bool OK = dfs (total-1, ans, n, k, nodes);
                if (OK) {
                    return true;
                }
                nodes[t] = false;
            }
        }
        ans.pop_back();
        return false;
    }    
    
public:
    string crackSafe(int n, int k) {
        bool nodes[10000] = {false};
        string ans(n, '0');
        int total = pow(k, n);
        nodes[0] = true;
        dfs(total - 1, ans, n, k, nodes);
        return ans;
    }
};

