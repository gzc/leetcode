class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> sizes(n+1, 0);
        vector<unordered_map<int, int>> graph(n + 1);
        for (const vector<int>& edge : edges) {
            graph[edge[0]][edge[1]]++;
            graph[edge[1]][edge[0]]++;
            sizes[edge[0]]++;
            sizes[edge[1]]++;
        }
        
        vector<int> prefix_sum(100001, 0);
        for (int i = 1; i < sizes.size(); i++) {
            prefix_sum[sizes[i]]++;
        }
        for (int i = 100000; i >= 1; i--) {
            prefix_sum[i-1] += prefix_sum[i];
        }
        
        vector<int> answer;
        for (int query : queries) {
            int total = 0;
            
            for (int i = 1; i <= n; i++) {
                const unordered_map<int, int>& mymap = graph[i];
                
                int target = query - sizes[i];
                int current = 0;
                for (const auto& it : mymap) {
                    int neighbor = it.first;
                    if (sizes[neighbor] > target) {
                        current--;
                    }
                    int count = sizes[i] + sizes[neighbor] - it.second; 
                    if (count > query) {
                        current++;
                    }
                }
                if (sizes[i] > target) {
                    current--;
                }
                current += prefix_sum[target < 0 ? 0 : target+1];
                total += current;
            }
            answer.push_back(total / 2);
        }
        
        return answer;
    }
};
