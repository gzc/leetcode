class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        int n = tickets.size();
        for(int i = 0; i < n; ++ i){
            g[tickets[i].first].insert(tickets[i].second);
        }
        dfs("JFK", ans, 1, n);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    void dfs(string u, vector<string> &ans, int dep, int tot){
        while(g[u].size()){
            string v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v, ans, dep + 1, tot);
        }
        ans.push_back(u);
    }
    
private:
    unordered_map<string, multiset<string> > g;
    
};