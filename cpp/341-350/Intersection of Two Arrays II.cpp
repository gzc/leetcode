class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mymap;
        vector<int> ans;
        for(int ele : nums1) mymap[ele] += 1;
        for(int ele : nums2) {
            if(mymap.count(ele) > 0 && mymap[ele] > 0) {
                ans.push_back(ele);
                mymap[ele] -= 1;
            }
        }
        return ans;
    }
};
