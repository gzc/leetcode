class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> myset, ans;
        for (int ele : nums1) myset.insert(ele);
        for (int ele : nums2) 
            if(myset.count(ele) > 0)
                ans.insert(ele);
        return vector<int>(ans.begin(), ans.end());
    }
};
