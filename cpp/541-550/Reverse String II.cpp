class Solution {
    
    void _reverse(string &str, int i, int j) {
        while (i < j) swap(str[i++], str[j--]);
    }
    
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (true) {
            if (i >= s.length()) break;
            int start = i;
            int end = min(i + 2*k, (int)s.length()) - 1;
            _reverse(s, start, min(end, start + k - 1) );
            i = end + 1;
        }
        return s;
    }
};
