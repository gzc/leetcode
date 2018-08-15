class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> color(N+1, 0);
        map<int, vector<int>> al;
        for (auto& d: dislikes) {
            al[d[0]].push_back(d[1]);
            al[d[1]].push_back(d[0]);
        }
        queue<int> q;
        for (auto e : al) {
            if (color[e.first] == 0) { // untouched person
                color[e.first] = 1;
                q.push(e.first);
                while (!q.empty()) {
                    int s = q.front(); q.pop();
                    for (int x : al[s]) { // all neighbors of s
                        if (color[x] == 0) {
                            color[x] = 3 - color[s];
                            q.push(x);
                        }
                        else if (color[x] != 3 - color[s])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
