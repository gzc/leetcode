class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2) 
            { return p1[1] < p2[1] || (p1[1] == p2[1] && p1[0] > p2[0]); };
        sort(intervals.begin(), intervals.end(), comp);
        
        int n = intervals.size();
        vector<int> count(n, 2);
        int ans = 0;
        int end = -1;
        
        for (int i = 0; i < n; i++) {
            if (count[i] == 0) continue;
            ans += count[i];
            for (int j = i+1; j < n; j++) {
                if (count[j] > 0) {
                    if (count[i] == 2) {
                        int overlap = intervals[i][1] - intervals[j][0] + 1;
                        if (overlap > 0) {
                            count[j] -= overlap;
                            count[j] = max(0, count[j]);
                        }
                    } else if (count[i] == 1) {
                        int overlap = intervals[i][1] >= intervals[j][0] ? 1 : 0;
                        count[j] -= overlap;
                    }
                }
            }
        }
        
        return ans;
    }
};
