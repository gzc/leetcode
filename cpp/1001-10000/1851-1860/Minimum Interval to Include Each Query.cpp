class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int m = queries.size();

        sort(intervals.begin(), intervals.end(),[](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[1] - lhs[0] < rhs[1] - rhs[0];
        });
        
        set<pair<int, int>> myset;
        for (int i = 0; i < m; i++) {
            myset.insert({queries[i], i});
        }
        
        vector<int> ans(m, -1);
        for (const vector<int>& interval : intervals) {
            auto it = myset.lower_bound({interval[0], 0});
            
            while (it != myset.end() && it->first <= interval[1]) {
                ans[it->second] = interval[1] - interval[0] + 1;
                it = myset.erase(it);
            }
            
            if (myset.empty()) break;
        }
        
        return ans;
    }
};
