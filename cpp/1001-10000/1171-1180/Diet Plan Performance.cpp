class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int ans = 0;
        int sum = accumulate(calories.begin(), calories.begin() + k, 0);
        
        for (int i = k; i <= calories.size(); i++) {
            if (sum > upper) ans++;
            if (sum < lower) ans--;
            
            if (i >= calories.size()) break;
            
            sum = sum - calories[i - k];
            sum = sum + calories[i];
        }
        
        return ans;
    }
};
