class Solution {
public:
    map<int, vector<pair<int,int>>> mp;
    
    void dfs(int r, int c, vector<vector<int>> &g, int cnt) {
        if ( r < 0 || c < 0 || r >= g.size() || c >= g[0].size()) return;
        if (g[r][c] != 1) return;
        g[r][c] = cnt;
        mp[cnt].push_back({r,c});
        dfs(r+1,c,g,cnt);
        dfs(r-1,c,g,cnt);
        dfs(r,c+1,g,cnt);
        dfs(r,c-1,g,cnt);
    }
    
    vector<pair<int,int>> norm(vector<pair<int,int>> v) {
        vector<vector<pair<int,int>>> s(8);
        // compute rotations/reflections.
        for (auto p:v) {
            int x = p.first, y = p.second;
            s[0].push_back({x,y});
            s[1].push_back({x,-y});
            s[2].push_back({-x,y});
            s[3].push_back({-x,-y});
            s[4].push_back({y,-x});
            s[5].push_back({-y,x});
            s[6].push_back({-y,-x});
            s[7].push_back({y,x});
        }
        for (auto &l:s) sort(l.begin(),l.end());
        for (auto &l:s) {
            for (int i = 1; i < v.size(); ++i) 
                l[i] = {l[i].first-l[0].first, l[i].second - l[0].second};
            l[0] = {0,0};
        }
        sort(s.begin(),s.end());
        return s[0];
    }
    
    int numDistinctIslands2(vector<vector<int>>& g) {
        int cnt = 1;
        set<vector<pair<int,int>>> s;
        for (int i = 0; i < g.size(); ++i) for (int j = 0; j < g[i].size(); ++j) if (g[i][j] == 1) {
            dfs(i,j,g, ++cnt);
            s.insert(norm(mp[cnt]));
        }
        
        return s.size();
    }
};
