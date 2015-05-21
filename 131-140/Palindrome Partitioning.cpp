class Solution {
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret, vector<vector<bool>> &p) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(p[index][i]) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret, p);
                path.pop_back();
            }
        }
    }
    
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<vector<bool> >p(s.length(), vector<bool>(s.length(), false));
        for(int i = 0;i < s.length();i++)
        {
            for(int j = 0;j < s.length()-i;j++)
            {
                if(i == 0)
                    p[j][j] = true;
                else
                {
                    if(s[j] == s[j+i])
                        p[j][j+i] = j+1 <= j+i-1 ? p[j+1][j+i-1] : true;
                    else
                        p[j][j+i] = false;
                }
            }
        }

        vector<string> path;
        dfs(0, s, path, ret, p);

        return ret;
    }
    
};
