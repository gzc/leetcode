class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, a = 0, b = 1;

        for(int n: nums){
            if (a == n) {
                cnt1++;
            } else if (b == n) {
                cnt2++;
            } else if (cnt1 == 0) {
                a = n;
                cnt1 = 1;
            } else if (cnt2 == 0){
                b = n;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int n: nums){
            if (n == a)   cnt1++;
            else if (n == b)  cnt2++;
        }

        vector<int> res;
        if (cnt1 > nums.size()/3)   res.push_back(a);
        if (cnt2 > nums.size()/3)   res.push_back(b);
        return res;
    }
};
