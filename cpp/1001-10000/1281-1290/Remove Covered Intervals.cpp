class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = intervals.size();
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if (l >= left && r <= right) ans--;
            else {
                left = l;
                right = r;
            }
        }
        return ans;
    }
};
