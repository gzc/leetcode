struct node {
public:
    int starttime;
    int finishtime;
    char ch;
    int color;
    set<int> edges;
};

bool myfunction (node i,node j) { return (i.finishtime > j.finishtime); }

class Solution {
    
    bool flag;
    int mytime;
    
    node nodes[26];
    
    void dfs_visit(int u)
    {
        if(nodes[u].color == 1) { flag = true; return;}
        nodes[u].color = 1;
        nodes[u].starttime = mytime++;
        for(set<int>::iterator it = nodes[u].edges.begin(); it != nodes[u].edges.end(); it++)
        {
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
        set<char> allchars;
        
        for(int i = 0;i < words.size();i++)
            for(int j = 0;j < words[i].length();j++)
                allchars.insert(words[i][j]);
        
        for(int i = 0;i < words.size()-1;i++)
        {
            string previous = words[i];
            string next = words[i+1];
            int len = min(previous.length(), next.length());
            for(int j = 0;j < len;j++)
            {
                char ch1 = previous[j];
                char ch2 = next[j];
                allchars.insert(ch1);
                allchars.insert(ch2);
                if(ch1 == ch2) continue;
                nodes[ch1 - 'a'].ch = ch1;
                nodes[ch2 - 'a'].ch = ch2;
                nodes[ch1 - 'a'].edges.insert(ch2 - 'a');
                break;
            }
            
        }
        
        for(int i = 0;i < 26;i++)
            if(nodes[i].color == 0 && nodes[i].ch >= 'a')
                dfs_visit(i);
        
        if(flag) return "";
        sort(nodes, nodes+26,myfunction);
        
        for(int i = 0;i < 26;i++) {
            if(nodes[i].finishtime == 0) break;
            result += nodes[i].ch;
        }
        
        for(set<char>::iterator it = allchars.begin(); it != allchars.end(); it++)
        {
            if(result.find(*it) == string::npos)
                result += *it;
        }
        
        return result;
    }
    
};