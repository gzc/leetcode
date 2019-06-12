class Solution {
    int fact[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
    set<string> st;
    
    int uniquePerms(const string& s) {
        int cnt[26] = {};
        for (char ch : s) cnt[ch - 'A']++;
        int res = fact[s.size()];
        for (int n : cnt) res /= fact[n];
        return res;
    }
    
    int dfs(const string& s, string seq = "", int pos = 0) {
        if (pos >= s.size()) {
            return st.insert(seq).second ? uniquePerms(seq) : 0;
        }
        return dfs(s, seq, pos + 1) + dfs(s, seq + s[pos], pos + 1);
    }
    
public:
    int numTilePossibilities(string tiles) {
        sort(begin(tiles), end(tiles));
        return dfs(tiles) - 1;
    }
};
