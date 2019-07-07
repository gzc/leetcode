class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        unordered_map<int, int> record;
        for (const vector<int>& booking : bookings) {
            record[booking[0]-1] += booking[2];
            record[booking[1]] -= booking[2];
        }
        
        vector<int> ans(n, -1);
        
        int current = 0;
        for (int i = 0; i < n; i++) {
            current += record[i];
            ans[i] = current;
        }
        
        return ans;
    }
};
