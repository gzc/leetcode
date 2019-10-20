class Solution {

public:
    int balancedString(string s) {
        map<char, int> sum;
        int n = s.length();
        int needed = n/4;
        for (char ch : s) sum[ch]++;
        int totalQ = sum['Q'];
        int totalW = sum['W'];
        int totalE = sum['E'];
        int totalR = sum['R'];
        
        int ans = INT_MAX;
        
        int QInSubString = 0;
        int WInSubString = 0;
        int EInSubString = 0;
        int RInSubString = 0;
        
        int i = 0, j = -1;
        while (j < n) {
            int Qneeded = needed - (totalQ - QInSubString);
            int Wneeded = needed - (totalW - WInSubString);
            int Eneeded = needed - (totalE - EInSubString);
            int Rneeded = needed - (totalR - RInSubString);
            int temp = 0;
            if (Qneeded > 0)  temp += Qneeded;
            if (Wneeded > 0)  temp += Wneeded;
            if (Eneeded > 0)  temp += Eneeded;
            if (Rneeded > 0)  temp += Rneeded;

            if (temp <= (j-i+1)) {
                ans = min(ans, temp);
                if (s[i] == 'Q') QInSubString--;
                else if (s[i] == 'W') WInSubString--;
                else if (s[i] == 'E') EInSubString--;
                else if (s[i] == 'R') RInSubString--;
                i++;
            } else {
                j++;
                if (s[j] == 'Q') QInSubString++;
                else if (s[j] == 'W') WInSubString++;
                else if (s[j] == 'E') EInSubString++;
                else if (s[j] == 'R') RInSubString++;
            }
        }
        
        return ans;
    }
};
