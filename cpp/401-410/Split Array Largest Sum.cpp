class Solution {
public:
    typedef long long ll;

    bool canSplit(vector<int>& nums, int m, ll sum) {
        int c = 1;
        ll s = 0;
        for (int num : nums) {
            s += num;
            if (s > sum) {
                s = num;
                ++c;
            }
        }
        return c <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        ll left = 0, right = 0;
        for (int num : nums) {
            left = max(left, (ll)num);
            right += num;
        }
        while (left <= right) {
            ll mid = left + (right-left)/2;
            if (canSplit(nums, m, mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
};
