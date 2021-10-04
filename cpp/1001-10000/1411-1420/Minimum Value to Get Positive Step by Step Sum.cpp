class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minVal = INT_MAX;
        
        for (int v : nums) {
            sum += v;
            minVal = min(minVal, sum);
        }
        
        return 1 - minVal <= 0 ? 1 : 1 - minVal;
    }
};
