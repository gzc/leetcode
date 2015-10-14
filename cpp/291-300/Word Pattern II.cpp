class Solution {
    
    bool help(int pindex, int sindex, string &pattern, string &str, map<char,string>& m, map<string, bool>& check)
    {
        if(pindex == pattern.length() && sindex == str.length()) return true;
        if(pindex == pattern.length() || sindex == str.length()) return false;
        char cur = pattern[pindex];
        if(m.count(cur) == 0)
        {
            int maxlength = str.length() - sindex;
            for(int l = 1; l <= maxlength; l++)
            {
                string s = str.substr(sindex, l);
                if(check[s] == true) continue;
                m[cur] = s;
                check[s] = true;
                bool fff = help(pindex+1, sindex+l, pattern, str, m, check);
                if(fff) return true;
                m.erase(cur);
                check[s] = false;
            }
            return false;
        } else {
            string temp = m[cur];
            if(str.substr(sindex, temp.length()) == temp)
            {
                bool fff = help(pindex+1, sindex+temp.length(), pattern, str, m, check);
                if(fff) return true;
                else return false;
            } else {
                return false;
            }
        }
    }
    
public:
    bool wordPatternMatch(string pattern, string str) {
        
        map<char, string> m;
        map<string, bool> check;
        
        bool fff = help(0, 0, pattern, str, m, check);
        return fff;
    }
};