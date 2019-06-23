class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> v;
        for (const vector<int>& trip : trips) {
            v.push_back({trip[1], trip[0]});
            v.push_back({trip[2], -trip[0]});
        }
        sort(v.begin(), v.end());
        
        int passengers = 0;
        for (const pair<int, int>& e : v) {
            passengers += e.second;
            if (passengers > capacity) {
                return false;
            }
        }
        return true;
    }
};
