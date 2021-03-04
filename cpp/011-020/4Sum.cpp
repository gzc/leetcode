class Solution {
    
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>>result;
        int n = num.size();
        sort(num.begin(), num.end());
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && num[i-1] == num[i]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (j > (i + 1) && num[j-1] == num[j]) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                int partial_sum = num[i] + num[j];
                while (l < r) {
                    int sum = partial_sum + num[l] + num[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        result.push_back({num[i], num[j], num[l], num[r]});
                        while ((l + 1) < num.size() && num[l] == num[l+1]) l++;
                        l++;
                        while ((r - 1) >= 0 && num[r] == num[r - 1]) r--;
                        r--;
                    }
                }
            }
        }
        return result;
    }
};
