class Solution {
    
    const static int SCALE = 2;
    
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int add(0);
        int len1 = a.length();
        int len2 = b.length();
        int maxlen = max(len1, len2);
        
        string result("");
        
        for(int i = 0;i < maxlen;i++)
        {
            int d1 = (i < len1) ? a[i] - '0' : 0;
            int d2 = (i < len2) ? b[i] - '0' : 0;
            int d = d1+d2+add;
            add = d/SCALE;
            d = d%SCALE;
            result += ('0'+d);
        }
        
        if(add) result += "1";
        
        reverse(result.begin(), result.end());
        return result;
        
    }
};
