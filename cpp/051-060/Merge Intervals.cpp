class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        auto comp = [](const vector<int>& m, const vector<int>& n) {
            return m[0] < n[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> now = intervals[0];
        vector<vector<int>> result;
        for (int i = 1;i < intervals.size();i++) {
            const vector<int>& then = intervals[i];
            if (now[1] >= then[0]) {
                now[1] = max(now[1], then[1]);
            } else {
                result.push_back(now);
                now = then;
            }
        }
        result.push_back(now);
        return result;
    }
};
