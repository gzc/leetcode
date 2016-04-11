class Solution {
    
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> ans;
        int i(0),j(0);
        while(i < nums1.size() && j < nums2.size()) {
            if(greater(nums1, nums2, i, j)) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i == nums1.size())
        while(j < nums2.size())
        ans.push_back(nums2[j++]);
        else if(j == nums2.size())
        while(i < nums1.size())
        ans.push_back(nums1[i++]);
        
        return ans;
    }
    
    vector<int> getMax(vector<int> nums, int t) {
        stack<int> ans;
        vector<int> res;
        for(int i = 0;i < nums.size();i++) {
            while(!ans.empty() && (ans.size() + nums.size() - i > t) && ans.top() < nums[i])
            ans.pop();
            if(ans.size() < t)
            ans.push(nums[i]);
        }
        while(!ans.empty()) {
            res.insert(res.begin(), ans.top());
            ans.pop();
        }
        return res;
    }
    
    bool greater(vector<int> &nums1, vector<int> &nums2, int i, int j) {
        int len = min(nums1.size(), nums2.size());
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] > nums2[j]) return true;
            if(nums1[i] < nums2[j]) return false;
            i++;
            j++;
        }
        return (nums1.size()-i) >= (nums2.size()-j);
    }
    
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        
        int start = max(0, k-len2);
        int end = min(k, len1) + 1;
        
        for(int i = start;i < end;i++) {
            vector<int> tmp = merge(getMax(nums1, i), getMax(nums2, k - i));
            for(auto e : tmp)
            if(res.size() == 0) res = tmp;
            if(greater(tmp, res, 0, 0)) res = tmp;
        }
        
        return res;
    }
    
};
