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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        UF uf(n+1);
        for (auto& pipe : pipes) swap(pipe[0], pipe[2]);
        for (int i = 0; i < n; i++) pipes.push_back({wells[i], 0, i+1});
        sort(pipes.begin(), pipes.end());
        
        int ans = 0;
        for (auto& pipe : pipes) {
            int u = pipe[1];
            int v = pipe[2];
            if (!uf.connected(u, v)) {
                uf.Union(u, v);
                ans += pipe[0];
            }
        }
        
        return ans;
    }
};
