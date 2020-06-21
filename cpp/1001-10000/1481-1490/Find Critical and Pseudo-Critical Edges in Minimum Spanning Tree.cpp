class UF {
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    int N;
    
public:
    
    UF(int N) : parent(N), rank(N, 0), N(N), count(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    
    int find(int p) {
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
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> all_edges(1001);
        for (int i = 0; i < edges.size(); i++) {
            all_edges[edges[i][2]].push_back(i);
        }
        
        vector<vector<int>> ans(2);
        UF uf(n);
        
        for (int i = 1; i <= 1000; i++) {
            
            vector<int> candidates;
            
            for (int index : all_edges[i]) {
                const vector<int>& edge = edges[index];
                if (!uf.connected(edge[0], edge[1])) {
                    candidates.push_back(index);
                }
            }
            
            for (int check_index = 0; check_index < candidates.size(); check_index++) {
                UF copy = uf;
                for (int k = 0; k < candidates.size(); k++) {
                    if (check_index == k) continue;
                    const vector<int>& k_edge = edges[candidates[k]];
                    if (!copy.connected(k_edge[0], k_edge[1])) {
                        copy.Union(k_edge[0], k_edge[1]);
                    }
                }
                const vector<int>& check_edge = edges[candidates[check_index]];
                if (!copy.connected(check_edge[0], check_edge[1])) {
                    ans[0].push_back(candidates[check_index]);
                } else {
                    ans[1].push_back(candidates[check_index]);
                }
            }
            
            for (int k = 0; k < candidates.size(); k++) {
                const vector<int>& current_edge = edges[candidates[k]];
                if (!uf.connected(current_edge[0], current_edge[1])) {
                    uf.Union(current_edge[0], current_edge[1]);
                }
            }
        }
        
        return ans;
    }
};
