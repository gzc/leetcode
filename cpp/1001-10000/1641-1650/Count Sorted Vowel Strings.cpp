class Solution {
public:
    int countVowelStrings(int n) {
        map<char, int> dp;
        dp['a'] = 1;
        dp['e'] = 1;
        dp['i'] = 1;
        dp['o'] = 1;
        dp['u'] = 1;
        
        for (int i = 1; i < n; i++) {
            map<char, int> tmp;
            tmp['a'] = dp['a'];
            tmp['e'] = dp['a'] + dp['e'];
            tmp['i'] = dp['a'] + dp['e'] + dp['i'];
            tmp['o'] = dp['a'] + dp['e'] + dp['i'] + dp['o'];
            tmp['u'] = dp['a'] + dp['e'] + dp['i'] + dp['o'] + dp['u'];
            dp = tmp;
        }
        
        return dp['a'] + dp['e'] + dp['i'] + dp['o'] + dp['u'];
    }
};
