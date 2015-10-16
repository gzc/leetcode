class Solution {
    
    int r;
    map<char, char> m;
    char chs[5] = {'1','6','9','8','0'};
    
    bool check(string low, string high)
    {
        if(high.length() > low.length()) return true;
        if(high.length() < low.length()) return false;
        return high <= low;
    }
    
    void help(string temp, int cur, int &n, string &low, string &high)
    {
        if(n >= 2 && temp[0] == '0') return;
        if(cur == (n+1)/2)
        {
            if(check(low, temp) && check(temp, high)) r++;
            return;
        }
        
        for(int i = 0;i <= 4;i++)
        {
            temp[cur] = chs[i];
            temp[n - cur - 1] = m[chs[i]];
            if(n % 2 == 1 && cur == n/2)
            {
                if(chs[i] == m[chs[i]])
                    help(result, temp, cur+1, n);
            }
            else help(result, temp, cur+1, n);
        }
    }
    
public:
    int strobogrammaticInRange(string low, string high) {
        m['6'] = '9';
        m['9'] = '6';
        m['1'] = '1';
        m['8'] = '8';
        m['0'] = '0';
        r = 0;
        
        int n1 = low.length();
        int n2 = high.length();
        for(int n = n1;n <= n2;n++)
        {
            string temp(n,'1');
            help(temp,0,n,low,high);
        }
        
        return r;
    }
};
