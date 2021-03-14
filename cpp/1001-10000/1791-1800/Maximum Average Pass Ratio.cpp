class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            double a_original = a.first * 1.0 / a.second;
            double a_new = (a.first + 1) *1.0 / (a.second + 1);
            double b_original = b.first * 1.0 / b.second;
            double b_new = (b.first + 1) *1.0 / (b.second + 1);
            return (a_new - a_original) < (b_new - b_original);
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (vector<int>& myclass : classes) {
            pq.push({myclass[0], myclass[1]});
        }
        
        for (int i = 0; i < extraStudents; i++) {
            pair<int, int> cur = pq.top();
            pq.pop();
            
            cur.first++;
            cur.second++;
            
            pq.push(cur);
        }
        
        double sum = 0.0;
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            sum += (1.0 * cur.first / cur.second);
        }
        
        return sum / classes.size();
    }
};
