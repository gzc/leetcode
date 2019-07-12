class Solution {
    vector<int> getInterval(const vector<int>& a, const vector<int>& b) {
        vector<int> ans(2, 0);
        ans[0] = max(a[0], b[0]);
        ans[1] = min(a[1], b[1]);
        return ans;
    }
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int>> ans;
        
        while (i < A.size() && j < B.size()) {
            const vector<int>& first = A[i];
            const vector<int>& second = B[j];
            
            if (first[1] < second[0]) {
                i++;
            } else if (second[1] < first[0]) {
                j++;
            } else {
                ans.emplace_back(getInterval(first, second));
                if (first[1] < second[1]) {
                    i++;
                } else if (first[1] > second[1]) {
                    j++;
                } else {
                    i++;
                    j++;
                }
            }
        }
        
        return ans;
    }
};
