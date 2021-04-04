class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k, 0);
        
        map<int, set<int>> activities;
        for (const vector<int>& log : logs) {
            activities[log[0]].insert(log[1]);
        }
        
        for (auto [id, activity] : activities) {
            res[activity.size() - 1]++;
        }
        
        return res;
    }
};
