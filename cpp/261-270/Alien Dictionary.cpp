struct node {
    char ch;
    int color;
    set<int> edges;
};

class Solution {
    node nodes[26];
    
    bool dfs_visit(int u, string& result) {
        if(nodes[u].color == 1) { return false; }
        nodes[u].color = 1;
        for(auto it = nodes[u].edges.begin(); it != nodes[u].edges.end(); it++) {
            if(nodes[*it].color != 2)
                if (!dfs_visit(*it, result))
                    return false;
        }
        result = nodes[u].ch + result;
        nodes[u].color = 2;
        return true;
    }
    
public:
    string alienOrder(vector<string>& words) {
        for (int i = 0;i < words.size();i++)
            for (int j = 0;j < words[i].length();j++)
                nodes[words[i][j] - 'a'].ch = words[i][j];
        
        for (int i = 0;i < words.size()-1;i++) {
            const string& previous = words[i];
            const string& next = words[i+1];
            int len = min(previous.length(), next.length());
            for (int j = 0;j < len;j++) {
                char ch1 = previous[j];
                char ch2 = next[j];
                if (ch1 == ch2) continue;
                nodes[ch1 - 'a'].edges.insert(ch2 - 'a');
                break;
            }
        }
        
        string result("");
        for (int i = 0;i < 26;i++)
            if (nodes[i].color == 0 && nodes[i].ch >= 'a')
                if (!dfs_visit(i, result))
                    return "";

        return result;
    }
    
};
