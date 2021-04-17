class Solution {
    int mod = 1e9 + 7;
    
    long pow(long a, long p, long mod) {
        long ans = 1;
        while (p > 0) {
            if (p & 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            p = p >> 1;
        }
        return ans;
    }
public:
    
    int makeStringSorted(string s) {
        map<int, int> freq; 
        for (char ch: s) {
            freq[ch - 'a']++;
        }
        
        int n = s.length();
        vector<long> fact(s.size() + 1, 1);
        for (int i = 1; i <= s.size(); i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        
        long ans = 0;
        for (char ch : s) {
            long freq_sum = 0;
            long duplicates = 1;
            for (int i = 0; i < 26; i++) {
                if (i < (ch - 'a')) {
                    freq_sum += freq[i];
                }
                duplicates = (duplicates * fact[freq[i]]) % mod;
            }
            ans += (freq_sum * fact[n - 1] % mod) * pow(duplicates, mod - 2, mod);
            ans %= mod;
            n--;
            freq[ch - 'a']--;
        }
        return ans;
    }
};
