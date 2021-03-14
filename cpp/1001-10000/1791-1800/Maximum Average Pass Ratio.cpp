/*
 * Solution 1: Compute increase every time. It's a bit slow.
 */
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

/*
 * Solution 2: Pre-compute increase.
 */
class Solution {
    double GetIncrease(int dividend, int divisor) {
        double original_value = dividend * 1.0 / divisor;
        double new_value = (dividend + 1) * 1.0 / (divisor + 1);
        return new_value - original_value;
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const pair<pair<int, int>, double>& a, const pair<pair<int, int>, double>& b) {
            return a.second < b.second;
        };
        
        priority_queue<pair<pair<int, int>, double>, vector<pair<pair<int, int>, double>>, decltype(cmp)> pq(cmp);
        for (vector<int>& myclass : classes) {
            pq.push({{myclass[0], myclass[1]}, GetIncrease(myclass[0], myclass[1])});
        }
        
        for (int i = 0; i < extraStudents; i++) {
            pair<pair<int, int>, double> cur = pq.top();
            pq.pop();
            
            cur.first.first++;
            cur.first.second++;
            cur.second = GetIncrease(cur.first.first, cur.first.second);
            
            pq.push(cur);
        }
        
        double sum = 0.0;
        while (!pq.empty()) {
            pair<pair<int, int>, double> cur = pq.top();
            pq.pop();
            sum += cur.first.first * 1.0 / cur.first.second;
        }
        
        return sum / classes.size();
    }
};
