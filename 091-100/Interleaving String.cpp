class Solution {
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        
        bool table[s1.length()+1][s2.length()+1];
        for(int i = 0;i <= s1.length();i++)
            for(int j = 0;j <= s2.length();j++)
                table[i][j] = false;

        
        table[0][0] = true;
        for(int i = 1;i <= s1.length();i++)
            if(s3[i-1] == s1[i-1] && table[i-1][0])
                table[i][0] = true;

        for(int j = 1;j <= s2.length();j++)
            if(s3[j-1] == s2[j-1] && table[0][j-1])
                table[0][j] = true;
        
        for(int i = 1;i <= s1.length();i++)
        {
            for(int j = 1;j <= s2.length();j++)
            {
                if(s3[i+j-1] == s1[i-1] && table[i-1][j] == true)
                    table[i][j] = true;
                if(s3[i+j-1] == s2[j-1] && table[i][j-1] == true)
                    table[i][j] = true;
            }
        }

        return table[s1.length()][s2.length()];
    }
    
};
