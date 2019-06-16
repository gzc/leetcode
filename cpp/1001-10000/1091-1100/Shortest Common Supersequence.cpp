class Solution {
    
    string lcs(const string& str1, const string& str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        map<pair<int,int>, pair<int, int>> from;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    from[{i, j}] = {i-1, j-1};
                } else {
                    if (dp[i-1][j] > dp[i][j-1]) {
                        from[{i, j}] = {i-1, j};
                    } else {
                        from[{i, j}] = {i, j-1};
                    }
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = m;
        int j = n;

        string ans;

        while (i > 0 && j > 0) {
            auto p = from[{i, j}];

            if (dp[i][j] == dp[p.first][p.second] + 1) {
                ans = str1[i-1] + ans;
            }

            i = p.first;
            j = p.second;
        }

        return ans;
    }
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string temp = lcs(str1, str2);

        map<int, string> mymap;

        int j = 0;
        for (int i = 0; i < temp.size(); i++) {
            char ch = temp[i];
            string s;
            while (str1[j] != ch) {
                s = s + str1[j];
                j++;
            }
            j++;
            mymap[i] = s;
        }
        mymap[temp.size()] = str1.substr(j);

        j = 0;
        for (int i = 0; i < temp.size(); i++) {
            char ch = temp[i];
            string s;
            while (str2[j] != ch) {
                s = s + str2[j];
                j++;
            }
            j++;
            mymap[i] += s;
        }
        mymap[temp.size()] += str2.substr(j);

        string ans;
        for (int i = 0; i < temp.size(); i++) {
            ans += mymap[i];
            ans = ans + temp[i];
        }
        ans += mymap[temp.size()];

        return ans;
    }
};
