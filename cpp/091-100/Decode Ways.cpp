class Solution {
    
    bool valid(char ch1, char ch2)
    {
        if(ch1 == '1')
            return true;
        else if(ch1 == '2')
        {
            if(ch2 <= '6')
                return true;
            return false;
        }
        return false;
    }
    
public:
    int numDecodings(string s) {
        
        int n = s.length();
        if(n == 0) return 0;
        
        int *p = new int[n+1];
        p[0] = 1;
        p[1] = 1;
        if(s[0] == '0') p[1] = 0;
        
        for(int i = 0;i < n-1;i++)
        {
            if(s[i+1] == '0')
            {
                if (s[i] >= '1' && s[i] <= '2')
                    p[i+2] = p[i];
                else 
                    p[i+2] = 0;
            } else if(s[i] == '0') {
                p[i+2] = p[i+1];
            }
            else if(valid(s[i], s[i+1]))
                p[i+2] = p[i]+p[i+1];
            else
                p[i+2] = p[i+1];
        }
        
        return p[n];
    }
};
