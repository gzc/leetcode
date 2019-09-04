class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> data(s.length()+1, vector<int>(26, 0));
        
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 26; j++) {
                data[i+1][j] = data[i][j] + (s[i] - 'a' == j ? 1 : 0);
            }
        }
        
        vector<bool> answers;
        
        for (const vector<int>& query : queries) {
            int needed = 0;
            for (int j = 0; j < 26; j++) {
                int d = data[query[1]+1][j] - data[query[0]][j];
                if (d % 2 == 1) needed++;
            }
            if ((query[1] - query[0]) % 2 == 0) needed--;
            if (needed <= 2*query[2]) answers.push_back(true);
            else answers.push_back(false);
        }
        
        return answers;
    }
};
