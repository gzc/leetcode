class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        
        sort(begin(courses), end(courses), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });
        
        int totalTime = 0;
        for (int i = 0; i < courses.size(); i++) {
            vector<int> current = courses[i];
            if (current[0] + totalTime <= current[1]) {
                totalTime += current[0];
                pq.push(current);
            } else if (!pq.empty()) {
                vector<int> mayDiscard = pq.top();
                if (current[0] < mayDiscard[0]) {
                    pq.pop();
                    pq.push(current);
                    totalTime += (current[0] - mayDiscard[0]);
                }
            }
        }
        
        return pq.size();
    }
};
