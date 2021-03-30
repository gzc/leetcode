class Solution {
    bool dfs(char ch,
             unordered_map<char, vector<char>>& graph,
             unordered_map<char, int>& colors,
             string& order) {
        colors[ch] = 1;
        for (char neighbor : graph[ch]) {
            if (colors[neighbor] == 1) {
                return true;
            }
            if (colors[neighbor] == 0) {
                bool has_circle = dfs(neighbor, graph, colors, order);
                if (has_circle) {
                    return true;
                }
            }
        }
        order.push_back(ch);
        colors[ch] = 2;
        return false;
    }
    
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        for (int i = 1; i < words.size(); i++) {
            int len = min(words[i-1].size(), words[i].size());
            for (int j = 0; j < len; j++) {
                if (words[i-1][j] != words[i][j]) {
                    graph[words[i-1][j]].push_back(words[i][j]);
                    break;
                }
                if (j == len - 1 && words[i].size() < words[i-1].size()) {
                    return "";
                }
            }
        }
        
        unordered_map<char, int> colors;
        for (const string& word : words) {
            for (char ch : word) {
                colors[ch] = 0;
            }
        }
        
        string res;
        for (const auto& [ch, color] : colors) {
            if (color == 0) {
                if (dfs(ch, graph, colors, res)) {
                    return "";
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
