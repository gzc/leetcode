class Solution {
    
    map<char, char> m;
    char chs[5] = {'1','6','9','8','0'};
    
    void help(vector<string>& result, string temp, int cur, int n)
    {
        // "0" is OK, "0xxxxx" is not
        if (n > 1 && temp[0] == '0') return;
        if (cur == (n+1)/2)
        {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0;i <= 4;i++)
        {
            temp[cur] = chs[i];
            temp[n - cur - 1] = m[chs[i]];
            if (n % 2 == 1 && cur == n/2 && chs[i] != m[chs[i]]) { }  //奇数长度并且是6,9什么都不做
            else help(result, temp, cur+1, n);
        }
    }
    
public:
    vector<string> findStrobogrammatic(int n) {
        m['6'] = '9';
        m['9'] = '6';
        m['1'] = '1';
        m['8'] = '8';
        m['0'] = '0';
        
        vector<string> result;
        string temp(n, '1');
        help(result, temp, 0, n);
        return result;
    }
    
};
