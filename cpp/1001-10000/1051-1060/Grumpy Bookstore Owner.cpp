class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int gained = 0;
        int max_gained = 0;
        int normal_gained = 0;
        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 0) normal_gained += customers[i];
            gained += (grumpy[i] == 1 ? customers[i] : 0);
            if (i >= X) {
                gained -= (grumpy[i-X] == 1 ? customers[i-X] : 0);
            }
            max_gained = max(max_gained, gained);
        }
        return normal_gained + max_gained;
    }
};
