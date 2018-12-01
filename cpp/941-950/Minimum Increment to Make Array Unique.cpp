class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, need = 0;
        for (int a: A) {
            res += max(need - a, 0);
            need = max(a, need) + 1;
        }
        return res;
    }
};
