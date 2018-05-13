class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A.front().empty()) return A;
        for (auto& v : A) reverse(v.begin(), v.end());
        for (auto& v : A) {
            for (int& e : v) {
                e = 1 - e;
            }
        }
        return A;
    }
};
