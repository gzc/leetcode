class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        unordered_map<int, int> days_to_clear;
        set<int> available_days;
        
        vector<int> ans(rains.size(), 1);
        for (int i = 0; i < rains.size(); i++) {
            
            if (rains[i] == 0) {
                available_days.insert(i);
            } else {
                if (days_to_clear.count(rains[i]) > 0) {
                    
                    auto it = available_days.lower_bound(days_to_clear[rains[i]]);
                    
                    if (it == available_days.end()) {
                        return vector<int>();
                    } else {
                        ans[*it] = rains[i];
                        days_to_clear.erase(rains[i]);
                        available_days.erase(it);
                    }
                    
                }
                days_to_clear[rains[i]] = i;
                ans[i] = -1;
            }
            
        }
        
        return ans;
    }
};
