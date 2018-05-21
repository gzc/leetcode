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
    
    bool similar(const string &a, const string &b) {
        int n = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i] && ++n > 2)
                return false;
        return true;
    }
    
public:
    int numSimilarGroups(vector<string>& A) {
        UF uf(A.size());
        for (int i = 0; i < A.size(); i++)
            for (int j = i + 1; j < A.size(); j++)
                if (similar(A[i], A[j]))
                    uf.Union(i, j);
        return uf.getCount();
    }
};
