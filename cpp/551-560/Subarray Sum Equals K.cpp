class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> mymap;
        int sum = 0;
        int ans = 0;
        mymap[0] = 1;
        
        for (int e : nums) {
            sum += e;
            int realTarget = sum - k;
            ans += mymap[realTarget];
            mymap[sum]++;
        }
        
        return ans;
    }
};
