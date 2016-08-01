class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m(matrix.size()), n(matrix[0].size());
        priority_queue<int> pq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.emplace(matrix[i][j]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
