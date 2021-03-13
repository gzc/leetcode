/*
 * Solution 1: DFS, slower when building graph.
 */
class Solution {
    void dfs(const vector<vector<int>>& graph, const vector<vector<string>>& accounts, int ind, vector<bool>& visited, set<string>& emails) {
        visited[ind] = true;
        for (int i = 1; i < accounts[ind].size(); i++) {
            emails.insert(accounts[ind][i]);
        }
        for (int neighbor : graph[ind]) {
            if (!visited[neighbor]) {
                dfs(graph, accounts, neighbor, visited, emails);
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            unordered_set<string> emails(accounts[i].begin()+1, accounts[i].end());
            for (int j = 0; j < i; j++) {
                if (accounts[i][0] != accounts[j][0]) {
                    continue;
                }
                for (int k = 1; k < accounts[j].size(); k++) {
                    if (emails.count(accounts[j][k]) > 0) {
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            if (!visited[i]) {
                set<string> emailSet;
                dfs(graph, accounts, i, visited, emailSet);
                res.resize(res.size() + 1);
                res.back().push_back(accounts[i][0]);
                for (const string& email : emailSet) {
                    res.back().push_back(email);
                }
            }
        }
        
        return res;
    }
};

/********************************************************************************/
/*
 * Solution 1: DFS, faster when building graph.
 */
class Solution {
    void dfs(const vector<set<int>>& graph, const vector<vector<string>>& accounts, int ind, vector<bool>& visited, set<string>& emails) {
        visited[ind] = true;
        for (int i = 1; i < accounts[ind].size(); i++) {
            emails.insert(accounts[ind][i]);
        }
        for (int neighbor : graph[ind]) {
            if (!visited[neighbor]) {
                dfs(graph, accounts, neighbor, visited, emails);
            }
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        vector<set<int>> graph(n);
        vector<bool> visited(n, false);
        
        unordered_map<string, set<int>> email_to_ids;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                email_to_ids[accounts[i][j]].insert(i);
            }
        }
        for (const auto& pair : email_to_ids) {
            const set<int>& ids_set = pair.second;
            vector<int> ids(ids_set.begin(), ids_set.end());
            for (int i1 = 0; i1 < ids.size(); i1++) {
                for (int i2 = i1 + 1; i2 < ids.size(); i2++) {
                    graph[ids[i1]].insert(ids[i2]);
                    graph[ids[i2]].insert(ids[i1]);
                }
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            if (!visited[i]) {
                set<string> emailSet;
                dfs(graph, accounts, i, visited, emailSet);
                res.resize(res.size() + 1);
                res.back().push_back(accounts[i][0]);
                for (const string& email : emailSet) {
                    res.back().push_back(email);
                }
            }
        }
        
        return res;
    }
};

/********************************************************************************/
/*
 * Solution 3: Union-Find.
 */
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
                mymap[accounts[i][j]].push_back(i);
            }
        }
        
        UF uf(n);
        for (const auto& it : mymap) {
            for (int i = 1; i < it.second.size(); i++) {
                uf.Union(it.second[0], it.second[i]);
            }
        }
        
        vector<vector<string>> result;
        unordered_map<int, int> root_2_result_idx;
        for (const auto& it : mymap) {
            int root = uf.find(it.second[0]);
            int resultSize = root_2_result_idx.size();
            if (root_2_result_idx.count(root) == 0) {
                root_2_result_idx[root] = resultSize;
                vector<string> temp;
                temp.push_back(accounts[root][0]);
                result.push_back(temp);
            }
            int index = root_2_result_idx[root];
            result[index].push_back(it.first);
        }

        return result;
    }
};
