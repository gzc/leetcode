class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0]*b[1] > b[0]*a[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        for (int i = 1; i < A.size(); i++) {
            vector<int> temp {1, A[i], 0};
            pq.push(temp);
        }
        
        while (--K) {
            vector<int> top = pq.top();
            pq.pop();
            int nindex = top[2] + 1;
            int next = A[nindex];
            if (next >= top[1]) continue;
            vector<int> temp {next, top[1], nindex};
            pq.push(temp);
        }
        
        return vector<int> {pq.top()[0], pq.top()[1]};
    }
};
