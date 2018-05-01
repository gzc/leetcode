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
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF uf(n+1);
        map<int, int> mymap;
        
        int c(-1), canA, canB;
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // two parent, must incorrect
            if (mymap.find(v) != mymap.end()) {
                c = v;
                canA = mymap[v];
                canB = u;
            }
            mymap[v] = u;
        }
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (u == canB && v == c) continue;
            if (uf.connected(u, v)) {
                if (c == -1) {
                    // Every node has only one parent
                    // The edge causes the circle must be the bad one
                    return edge;
                }
                return vector<int>{canA, c};
            }
            uf.Union(u, v);
        }
        
        return vector<int>{canB, c};
    }
};
