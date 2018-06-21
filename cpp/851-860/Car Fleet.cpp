class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> arrays(n);
        
        for (int i = 0; i < n; ++i)
            arrays[i] = make_pair(position[i], (target - position[i])*1.0 / speed[i]);
        
        auto cmp = [](const pair<int, double>& p1, const pair<int, double>& p2) {
            return p1.first > p2.first;
        };
        sort(arrays.begin(), arrays.end(), cmp);

        int ans = 0, t = 0;
        while (t < n-1) {
            if (arrays[t].second < arrays[t+1].second) ans++;
            else arrays[t+1] = arrays[t];
            t++;
        }

        return ans + (t == n-1 ? 1 : 0);
    }
};
