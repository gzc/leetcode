struct Entry {
    int start_time;
    int end_time;
    int profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> dp;
        int maximum_profit = 0;
        int n = profit.size();
        vector<Entry> entries;
        for (int i = 0; i < n; i++) {
            Entry entry;
            entry.start_time = startTime[i];
            entry.end_time = endTime[i];
            entry.profit = profit[i];
            entries.push_back(entry);
        }
        
        auto cmp = [](const Entry& lhs, const Entry& rhs) {
            return lhs.end_time <= rhs.end_time;
        };
        sort(entries.begin(), entries.end(), cmp);
        
        for (const Entry& entry : entries) {
            auto it = dp.upper_bound(entry.start_time);
            int max_profit_until_start_time = 0;
            if (it != dp.begin()) {
                max_profit_until_start_time = (--it)->second;
            }
            int current_profit = max_profit_until_start_time + entry.profit;
            maximum_profit = max(maximum_profit, current_profit);
            dp[entry.end_time] = maximum_profit;
        }
        
        return maximum_profit;
    }
};
