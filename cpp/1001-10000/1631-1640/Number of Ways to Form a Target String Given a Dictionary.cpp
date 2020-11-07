class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = target.length();
        long mod = 1e9 + 7;
        vector<long> res(n + 1);
        res[0] = 1;

        for (int i = 0; i < words[0].length(); ++i) {
            vector<int> count(26, 0);
            
            for (const string& w : words) {
                count[w[i] - 'a']++;
            }
            
            for (int j = n - 1; j >= 0; --j) {
                res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
                res[j + 1] %= mod;
            }
        }
        
        return res[n];
    }
};
