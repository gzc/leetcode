class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = g.size()-1, j = s.size()-1, res = 0;
        while(i>=0 && j>=0) {
            if (g[i] > s[j]) i--;
            else if (g[i--] <= s[j--]) res++;
        }
        return res;
    }
};
