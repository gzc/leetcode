class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = queries.size();

        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[1] - lhs[0] < rhs[1] - rhs[0];
        });
        
        set<pair<int, int>> myset;
        for (int i = 0; i < m; i++) {
            myset.insert({queries[i], i});
        }
        
        vector<int> ans(m, -1);
        for (const vector<int>& interval : intervals) {
            auto it1 = myset.lower_bound({interval[0], 0});
            auto it2 = myset.upper_bound({interval[1], 99999999});
            
            while (it1 != it2 && it1 != myset.end()) {
                ans[it1->second] = interval[1] - interval[0] + 1;
                it1 = myset.erase(it1);
            }
        }
        
        return ans;
    }
};
