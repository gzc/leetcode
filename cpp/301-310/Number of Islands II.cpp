class UF {
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    int N;
    
public:
    
    UF(int N) {
        parent.resize(N);
        rank.resize(N);
        this->N = N;
        count = N;
        for(int i = 0;i < N;i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    // path compression by halving
            p = parent[p];
        }
        return p;
    }
    
    int getCount() {
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
        if      (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }
};

class Solution {
    
    int col,row;
    
    int convert(int m, int n) {
        return col*m + n;
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        row = m;
        col = n;
        vector<int> res;
        UF uf(m*n);
        int count = 0;
        pair<int,int> pos[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<bool> marked(m*n+100, false);
        
        for(auto e : positions) {
            count++;
            int curisland = convert(e.first, e.second);
            marked[curisland] = true;
            for(int i = 0;i < 4;i++) {
                int posi = e.first + pos[i].first;
                int posj = e.second + pos[i].second;
                int neighborisland = convert(posi, posj);
                if(posi < 0 || posj < 0 || posi >= m || posj >= n || !marked[neighborisland]) continue;
                if(uf.connected(curisland, neighborisland)) {
                    continue;
                } else {
                    uf.Union(curisland, neighborisland);
                    count--;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};