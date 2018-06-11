class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> richer2;
        for (const auto& v : richer)
            richer2[v[1]].push_back(v[0]);
        vector<int> ans(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); i++) 
            dfs(i, quiet, ans, richer2);
        return ans;
    }

    int dfs(int i, const vector<int>& quiet, vector<int>& ans, unordered_map<int, vector<int>>& richer2) {
        if (ans[i] >= 0) return ans[i];
        ans[i] = i;
        for (int j : richer2[i])
            if (quiet[ans[i]] > quiet[dfs(j, quiet, ans, richer2)])
                ans[i] = ans[j];
        return ans[i];
    }
};
