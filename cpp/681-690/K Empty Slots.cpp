class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> days(n, 0);
        
        for (int i = 0; i < n; i++) {
            days[flowers[i]-1] = i;
        }
        
        int ans = INT_MAX;
        int left = 0;
        while (left + k + 1 < n) {
            int right = left + k + 1;
            int startDay = days[left];
            int endDay = days[right];
            bool invalid = false;
            for (int i = left + 1; i < right; i++) {
                if (days[i] > startDay && days[i] > endDay) continue;
                invalid = true;
                left = i;
                break;
            }
            if (!invalid) {
                ans = min(ans, 1 + max(startDay, endDay));
                left = right;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
