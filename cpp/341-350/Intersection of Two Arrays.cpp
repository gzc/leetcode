class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> myset;
        set<int> ans;
        for(int ele : nums1) myset.insert(ele);
        for(int ele : nums2) 
            if(myset.count(ele) > 0)
                ans.insert(ele);
        vector<int> result(ans.begin(), ans.end());
        return result;
    }
};
