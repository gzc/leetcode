class Solution {

public:
    int balancedString(string s) {
        map<char, int> sum;
        int n = s.length();
        int needed = n/4;
        for (char ch : s) sum[ch]++;
        int ans = INT_MAX;
        
        map<char, int> chInSubString;
        
        int i = 0, j = -1;
        while (j < n) {
            int temp = 0;
            for (char ch : {'Q', 'W', 'E', 'R'}) {
                int ch_needed = needed - (sum[ch] - chInSubString[ch]);
                if (ch_needed > 0) temp += ch_needed;
            }

            if (temp <= (j-i+1)) {
                ans = min(ans, temp);
                chInSubString[s[i]]--;
                i++;
            } else {
                j++;
                chInSubString[s[j]]++;
            }
        }
        
        return ans;
    }
};
