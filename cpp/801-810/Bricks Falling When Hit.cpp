class UF {
    
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int N;
    
public:
    
    UF(int N) : parent(N), rank(N, 0), size(N, 1), N(N) {
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
    
    int getSize(int p) {
        return size[find(p)];
    }
    
    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        
        // make root of smaller rank point to root of larger rank
        if (rank[rootP] < rank[rootQ])  { parent[rootP] = rootQ; size[rootQ] += size[rootP]; }
        else if (rank[rootP] > rank[rootQ]) { parent[rootQ] = rootP; size[rootP] += size[rootQ]; }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
            rank[rootP]++;
        }
    }
};

class Solution {
    
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid.front().size();
        int root = m * n;
        UF uf (m*n+1);
        vector<vector<int>> gridCopy(grid);
        for (const vector<int>& hit : hits) {
            gridCopy[hit[0]][hit[1]] = 0;
        }
        pair<int, int> pos[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for (int i = 0; i < n; i++) {
            if (gridCopy[0][i] == 1) {
                uf.Union(root, i);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (gridCopy[i][j] == 0) continue;
                for (auto it : pos) {
                    int ni = i + it.first;
                    int nj = j + it.second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || gridCopy[ni][nj] == 0) continue;
                    uf.Union(i*n+j, ni*n+nj);
                }
            }
        }
        
        vector<int> ans(hits.size(), 0);
        for (int k = hits.size() - 1; k >= 0; k--) {
            int x = hits[k][0];
            int y = hits[k][1];
            if (grid[x][y] == 0) continue;
            int count = uf.getSize(root);
            for (auto it : pos) {
                int nx = x + it.first;
                int ny = y + it.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || gridCopy[nx][ny] == 0) continue;
                uf.Union(x*n+y, nx*n+ny);
            }
            if (x == 0) uf.Union(root, y);
            gridCopy[x][y] = 1;
            ans[k] = max(0, uf.getSize(root) - count - 1);
        }
        
        return ans;
    }
};
