class Solution {
    
private:
    string preProcess(string s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);
        
        ret += "#$";
        return ret;
    }
    
public:
    string shortestPalindrome(string s) {
        
        string T = preProcess(s);
        int n = T.length();
        int P[n];
        int c = 0,r = 0;
        
        for(int i = 1;i < n;i++) {
            int mirror_i = 2*c-i;
            P[i] = r > i ? min(P[mirror_i], r-i) : 0;
            
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
            
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
            }
        }
        
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++) {
            if (1==i-P[i]) maxLen = P[i];
        }
        string temp = s.substr(maxLen);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
    
    
};
