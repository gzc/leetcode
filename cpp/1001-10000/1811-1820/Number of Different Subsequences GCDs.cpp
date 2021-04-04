class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<bool> vec(max_num + 1, false);
        for (int num: nums) {
            vec[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= max_num; i++) {
            int gcd = 0;
            for (int j = i; j <= max_num; j += i) {
                if (vec[j] == true) {
                    gcd = __gcd(gcd, j);
                }
            }
            if (gcd == i) ans++;
        }
        
        return ans;
    }
};
