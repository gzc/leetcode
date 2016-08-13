class Solution {
    
    const static int M = 128;
    
    int chs[M] = {0};
    
    void help(vector<string>& result, string &temp, const string &s, int cur)
    {
        int mid = s.length() / 2;
        if(s.length() % 2 == 0 && cur == mid) { result.push_back(temp); return;}
        if(s.length() % 2 == 1 && cur == mid) {
            for(int i = 0;i < M;i++){
                if(chs[i] == 1) {
                    temp[mid] = i;
                    result.push_back(temp);
                    return;
                }
            }
        }
        
        for(int i = 0;i < M;i++)
        {
            if(chs[i] >= 2) {
                temp[cur] = i;
                temp[s.length() - 1 - cur] = i;
                chs[i] -= 2;
                help(result, temp, s, cur+1);
                chs[i] += 2;
            }
        }
    }
    
public:
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        for (int i = 0;i < s.length();i++)
            chs[s[i]]++;
        
        int odd(0),even(0);
        for (int i = 0;i < M;i++) {
            if(chs[i] == 0) continue;
            if(chs[i] % 2 == 0) even++;
            else odd++;
        }
        
        if (odd >= 2) return result;
        if (s.length() % 2 == 0 && odd > 0) return result;
        
        string tmp(s.length(), 0);
        help(result, tmp, s, 0);
        return result;
    }
};
