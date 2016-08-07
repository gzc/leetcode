/*
 *  a[5] = 1  -1  5 -2  3
 *  sum    1   0  5  3  6
 *  if k = 2, when i = 3, mymap[1] = 0. the sum in the range is k.
 */

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        map<int, int> mymap;
        int sum(0), res(0);
        
        for (int i = 0;i < nums.size();i++) {
            sum += nums[i];
            if (sum == k) res = i+1;
            else {
                if (mymap.count(sum - k) > 0) res = max(res, i - mymap[sum-k]);
            }
            if (mymap.count(sum) == 0) mymap[sum] = i;
        }
        
        return res;
    }
};
