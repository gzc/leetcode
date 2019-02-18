class Solution {
    
    int ans;
    set<string> ans_set;
    
    void dfs(int i, const vector<vector<int>>& graph, const vector<int>& A, bool* visited, string temp, int count) {
        visited[i] = true;
        temp += to_string(A[i]);
        
        if (count == graph.size()) {
            if (ans_set.count(temp) == 0) {
                ans++;
                ans_set.insert(temp);
            }
        } else {
            set<int> performance;
            for (int k = 0; k < graph[i].size(); k++) {
                int index = graph[i][k];
                if (performance.count(A[index]) == 1) continue;
                if (visited[index] == false) {
                    performance.insert(A[index]);
                    dfs(index, graph, A, visited, temp, count+1);
                }
            }
        }
        
        visited[i] = false;
    }
    
public:
    int numSquarefulPerms(vector<int>& A) {
        vector<vector<int>> graph(A.size(), vector<int>());
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                if (i == j) continue;
                int val = A[i] + A[j];
                int root = sqrt(val);
                if (root*root == val) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        bool visited[12] = {false};
        
        set<int> performance;
        for (int i = 0; i < A.size(); i++) {
            if (performance.count(A[i]) == 1) continue;
            performance.insert(A[i]);
            dfs(i, graph, A, visited, "", 1);
        }
        
        return ans;
    }
};
