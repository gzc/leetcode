class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x > 0) {
            result = result * 10 + (x % 10);
            x /= 10;
        }
        return result;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int mod = 1e9+7;
        int res = 0;
        for (int num : nums) {
            int rnum = reverse(num);
            int diff = num - rnum;
            res += mymap[diff];
            res %= mod;
            mymap[diff]++;
        }
        
        return res;
    }
};
