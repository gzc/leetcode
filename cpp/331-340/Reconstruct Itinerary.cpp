class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        unordered_map<string, multiset<string> > g;
        for (int i = 0; i < tickets.size(); ++ i) {
            g[tickets[i].first].insert(tickets[i].second);
        }
        dfs("JFK", ans, g);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    void dfs(string u, vector<string> &ans, unordered_map<string, multiset<string> >& g){
        while (!g[u].empty()) {
            string v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v, ans, g);
        }
        ans.push_back(u);
    }
};
