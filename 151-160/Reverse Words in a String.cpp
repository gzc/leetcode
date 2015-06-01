class Solution {
public:
    void reverseWords(string &s) {
        string tmp = "";
        string s2;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == ' ')
            {
                if(tmp.length() > 0)
                {
                    s2 = tmp + " " + s2;
                    tmp = "";
                }
            }
            else tmp += s[i];
        }
        if(tmp.size() > 0) s2 = tmp + " " + s2;
        if(s2.length() == 0)
        {
            s = "";
            return;
        }
        s2.erase(s2.end()-1);
        s = s2;
    }
    
};
