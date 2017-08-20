class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m, b = n;
        for (const vector<int>& op : ops) {
            a = min(a, op[0]);
            b = min(b, op[1]);
        }
        return a*b;
    }
};
