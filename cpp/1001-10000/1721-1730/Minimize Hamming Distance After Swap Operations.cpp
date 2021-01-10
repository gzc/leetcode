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
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int ans = n;
        
        UF uf(n);
        for (const vector<int>& allowedSwap : allowedSwaps) {
            uf.Union(allowedSwap[0], allowedSwap[1]);
        }
        
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int parent = uf.find(i);
            groups[parent].push_back(i);
        }
        
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            int parent = uf.find(i);
            if (visited[parent]) {
                continue;
            }
            
            vector<int> group = groups[parent];
            unordered_map<int, int> mymap;
            
            for (int index : group) {
                mymap[target[index]]++;
            }
            for (int index : group) {
                if (mymap[source[index]] > 0) {
                    mymap[source[index]]--;
                    ans--;
                }
            }
            
            visited[parent] = true;
        }
        
        return ans;
    }
};
