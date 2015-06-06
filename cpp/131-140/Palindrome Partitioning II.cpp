class Solution {
public:
    int minCut(string s) {

        vector<vector<int> >p(s.length(), vector<int>(s.length(), 0xffff));
        for(int i = 0;i < s.length();i++)
            for(int j = 0;j < s.length()-i;j++)
                if(s[j] == s[j+i])
                    p[j][j+i] = j+1 <= j+i-1 ? p[j+1][j+i-1] : 0;


        for(int j = 1;j < s.length();j++)
            for(int i = 0;i < j;i++)
                p[0][j] = min(p[0][j], p[0][i]+p[i+1][j]+1);


        return p[0][s.length()-1];
    }
};
