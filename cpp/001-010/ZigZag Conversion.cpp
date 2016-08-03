class Solution {
public:
    string convert(string s, int numRows) {
        string v[numRows];
        int k(0), up(1);
        for (size_t i = 0;i < s.size();i++) {
            v[k] += s[i];
            k += up;
            if (k == (numRows-1) ) up = -1;
            if (k == 0) up = 1;
            // Deal with special condition when numRows == 1
            if (k == numRows) k = 0;
        }
        string res("");
        for (int i = 0;i < numRows;i++)
            res += v[i];
        return res;
    }
};
