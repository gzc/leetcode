#include<iostream>
#include<vector>

using namespace std;

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
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UF uf(4*n*n);
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                int root = 4 * (r * n + c);
                char val = grid[r][c];
                if (val != '\\') {
                    uf.Union(root + 0, root + 1);
                    uf.Union(root + 2, root + 3);
                }
                if (val != '/') {
                    uf.Union(root + 0, root + 2);
                    uf.Union(root + 1, root + 3);
                }

                // north south
                if (r + 1 < n)
                    uf.Union(root + 3, (root + 4 * n) + 0);
                if (r - 1 >= 0)
                    uf.Union(root + 0, (root - 4 * n) + 3);
                // east west
                if (c + 1 < n)
                    uf.Union(root + 2, (root + 4) + 1);
                if (c - 1 >= 0)
                    uf.Union(root + 1, (root - 4) + 2);
            }
        }
        
        return uf.getCount();
    }
};
