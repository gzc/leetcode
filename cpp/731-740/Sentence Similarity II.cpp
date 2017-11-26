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
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        map<string, int> mymap;
        int k = 0;
        for (const auto& pair : pairs) {
            if (mymap.count(pair.first) == 0) {
                mymap[pair.first] = k++;
            }
            if (mymap.count(pair.second) == 0) {
                mymap[pair.second] = k++;
            }
        }
        
        UF uf(k);
        for (const auto& pair : pairs) {
            uf.Union(mymap[pair.first], mymap[pair.second]);
        }
        
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] == words2[i]) continue;
            if (mymap.count(words1[i]) == 0 || mymap.count(words2[i]) == 0) return false;
            if (!uf.connected(mymap[words1[i]], mymap[words2[i]])) return false;
        }
        return true;
    }
};
