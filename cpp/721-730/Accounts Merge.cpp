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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string, vector<int>> mymap;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                mymap[email].push_back(i);
            }
        }
        
        UF uf(n);
        for (const auto& it : mymap) {
            for (int i = 1; i < it.second.size(); i++) {
                uf.Union(it.second[0], it.second[i]);
            }
        }
        
        vector<vector<string>> result;
        unordered_map<int, int> arrayMap; // root -> vector index
        for (const auto& it : mymap) {
            int root = uf.find(it.second[0]);
            int resultSize = arrayMap.size();
            if (arrayMap.count(root) == 0) {
                arrayMap[root] = resultSize;
                vector<string> temp;
                temp.push_back(accounts[root][0]);
                result.push_back(temp);
            }
            int index = arrayMap[root];
            result[index].emplace_back(it.first);
        }

        return result;
    }
};
