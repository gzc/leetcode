class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> idx(tasks.size());
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
        
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        long time = 1;
        for (int i = 0; i < idx.size() || !pq.empty();) {
            while (i < idx.size() && tasks[idx[i]][0] <= time) {
                pq.push({tasks[idx[i]][1], idx[i]});
                ++i;
            }
            if (!pq.empty()) {
                auto [processing_time, j] = pq.top();
                pq.pop();
                time += processing_time;
                res.push_back(j);
            } else {
                time = tasks[idx[i]][0];
            }
        }
        
        return res;
    }
};
