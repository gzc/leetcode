class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int max_time = -1;
        char ans;
        
        for (int i = 0; i < releaseTimes.size(); i++) {
            int time = (i == 0 ? releaseTimes[0] : releaseTimes[i] - releaseTimes[i-1]);
            if (time > max_time) {
                max_time = time;
                ans = keysPressed[i];
            } else if (time == max_time) {
                ans = max(ans, keysPressed[i]);
            }
        }
        
        return ans;
    }
};
