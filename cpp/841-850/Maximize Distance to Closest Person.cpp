class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last = -1;
        
        int ans = 0;
        
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                if (last < 0) {
                    ans = i;
                } else {
                    ans = max(ans, (i - last)/2);
                }
                last = i;
            }
        }
        
        ans = max(ans, (int)seats.size() - last - 1);
        
        return ans;
    }
};
