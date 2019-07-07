class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] <= b[0];
        };
        sort(clips.begin(), clips.end(), cmp);
        
        int k = 0;
        int next_k = -1;
        int ans = 0;
        
        for (const vector<int>& clip : clips) {
            if (clip[0] > k && clip[0] <= next_k) {
                ans++;
                k = next_k;
            }
            
            if (clip[0] <= k) {
                next_k = max(next_k, clip[1]);
                if (next_k >= T) return ans + 1;
            }
        }
        
        return next_k >= T ? ans : -1;
    }
};
