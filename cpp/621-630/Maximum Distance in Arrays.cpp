class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left = arrays[0].front();
        int right = arrays[0].back();
        int ans = 0;
        for (int i = 1; i < arrays.size(); i++) {
            ans = max(ans, max(abs(arrays[i].front() - right), abs(arrays[i].back() - left)));
            left = min(left, arrays[i].front());
            right = max(right, arrays[i].back());
        }
        return ans;
    }
};
