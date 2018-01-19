class Solution {

    bool dfs (vector<vector<char>>& pyramid, map<pair<char, char>, set<char>>& allowed, int i, int j) {
        if (i < 0) return true;
        
        char ch1 = pyramid[i+1][j];
        char ch2 = pyramid[i+1][j+1];
        auto key = make_pair(ch1, ch2);
        if (allowed.count(key) == 0) return false;
        set<char> chars = allowed[key];
        
        for (char ch : chars) {
            pyramid[i][j] = ch;
            int nexti, nextj;
            if (i == j) {
                nexti = i - 1;
                nextj = 0;
            } else {
                nexti = i;
                nextj = j + 1;
            }
            if(dfs(pyramid, allowed, nexti, nextj)) return true;
        }
        
        return false;
    }
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char, char>, set<char>> myallowed;
        for (string str : allowed) {
            myallowed[{str[0], str[1]}].insert(str[2]);
        }

        int n = bottom.length();
        vector<vector<char>> pyramid(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            pyramid[n-1][i] = bottom[i];
        }
        return dfs(pyramid, myallowed, n-2, 0);
    }
};
