struct node {
    int starttime;
    int finishtime;
    char ch;
    int color;
    set<int> edges;
};

bool myfunction (const node& i, const node& j) { return (i.finishtime > j.finishtime); }

class Solution {
    
    bool flag;
    int mytime;
    
    node nodes[26];
    
    void dfs_visit(int u) {
        if(nodes[u].color == 1) { flag = true; return; }
        nodes[u].color = 1;
        nodes[u].starttime = mytime++;
        for(auto it = nodes[u].edges.begin(); it != nodes[u].edges.end(); it++) {
            if(nodes[*it].color != 2)
                dfs_visit(*it);
        }
        nodes[u].finishtime = mytime++;
        nodes[u].color = 2;
    }
    
public:
    string alienOrder(vector<string>& words) {
        string result("");
        mytime = 0;
        
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
        
        for (int i = 0;i < 26;i++)
            if (nodes[i].color == 0 && nodes[i].ch >= 'a')
                dfs_visit(i);
        
        if (flag) return "";
        sort(nodes, nodes+26, myfunction);
        
        for (int i = 0;i < 26;i++)
            if (nodes[i].ch >= 'a')
                result += nodes[i].ch;

        return result;
    }
    
};
