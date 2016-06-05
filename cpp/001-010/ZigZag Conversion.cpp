class Solution {
public:
    string convert(string s, int nRows) {
        string v[nRows];
        int k(0), up(1);
        for(size_t i = 0;i < s.size();i++) {
            v[k] += s[i];
            k += up;
            if(k == (nRows-1) ) up = -1;
            if(k == 0) up = 1;
            if(k == nRows) k = 0;
        }
        string res("");
        for(int i = 0;i < nRows;i++)
            res += v[i];
        return res;
    }
};
