class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int, int>> values;
        for (int i = 0; i < aliceValues.size(); i++) {
            values.push_back({aliceValues[i], bobValues[i]});
        }
        
        auto cmp = [](const pair<int, int>& l, const pair<int, int>& r) {
            return (l.first+l.second) > (r.first+r.second);
        };
        
        sort(values.begin(), values.end(), cmp);
        
        int alice = 0;
        int bob = 0;
        for (int i = 0; i < values.size(); i++) {
            if (i % 2 == 0) {
                alice += values[i].first;
            } else {
                bob += values[i].second;
            }
        }
        
        if (alice > bob) return 1;
        else if (alice < bob) return -1;
        return 0;
    }
};
