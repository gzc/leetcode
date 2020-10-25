class UF {
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    int N;
    
    bool validate(int p) {
        return (p >= 0 && p < N);
    }
    
public:
    
    UF(int N) : parent(N), rank(N, 0), N(N), count(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    
    int find(int p) {
        if (!validate(p)) return -1;
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    // path compression by halving
            p = parent[p];
        }
        return p;
    }
    
    int getCount() const {
        return count;
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        
        // make root of smaller rank point to root of larger rank
        if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }
    
    ~UF() {}
};

class Solution {
    
    vector<vector<pair<int, int>>> group(const vector<pair<int, int>>& positions) {
        int n = positions.size();
        UF uf(n);
        
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        for (int i = 0; i < positions.size(); i++) {
            pair<int, int> pos = positions[i];
            rows[pos.first].push_back(i);
            cols[pos.second].push_back(i);
        }
        
        for (auto &it : rows) {
            vector<int> eles = it.second;
            for (int i = 1; i < eles.size(); i++) {
                uf.Union(eles[0], eles[i]);
            }
        }
        for (auto &it : cols) {
            vector<int> eles = it.second;
            for (int i = 1; i < eles.size(); i++) {
                uf.Union(eles[0], eles[i]);
            }
        }
        
        map<int, vector<pair<int, int>>> groups;
        for (int i = 0; i < n; i++) {
            groups[uf.find(i)].push_back(positions[i]);
        }
        
        vector<vector<pair<int, int>>> res;
        for (auto& it : groups) {
            res.push_back(it.second);
        }
        return res;
    }
    
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        map<int, vector<pair<int, int>>> mymap;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i][j];
                mymap[v].push_back({i, j});
            }
        }
        
        vector<vector<int>> rank(m, vector<int>(n, 0));
        
        unordered_map<int, int> rank_x_max;
        unordered_map<int, int> rank_y_max;
        
        for (auto& it : mymap) {
            int val = it.first;
            const vector<pair<int, int>>& positions = it.second;
            vector<vector<pair<int, int>>> positions_group = group(positions);
            
            for (const vector<pair<int, int>>& positions : positions_group) {
            
                int current_rank = 1;

                for (const pair<int, int>& cur : positions) {
                    int x = cur.first; int y = cur.second;

                    int rank_1 = 1;
                    if (rank_x_max.count(x) > 0) {
                        rank_1 = rank_x_max[x]+1;
                    }

                    int rank_2 = 1;
                    if (rank_y_max.count(y) > 0) {
                        rank_2 = rank_y_max[y]+1;
                    }

                    current_rank = max(current_rank, max(rank_1, rank_2));
                }
                
                for (const pair<int, int>& cur : positions) {
                    int x = cur.first; int y = cur.second;
                    rank[x][y] = current_rank;
                    rank_x_max[x] = current_rank;
                    rank_y_max[y] = current_rank;
                }
            }
            
        }
        
        return rank;
    }
};
