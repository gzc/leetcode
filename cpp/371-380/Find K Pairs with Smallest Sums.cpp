class Solution {
    
    typedef pair<int, vector<int>::iterator> mm;
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        
        auto cmp = [] (const mm& p1, const mm& p2) {
            return p1.first + *(p1.second) > p2.first + *(p2.second);
        };
        priority_queue<mm, vector<mm>, decltype(cmp)> pq(cmp);
        
        // Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
        // {1, iter}  {7, iter}  {11, iter}
        for (int v : nums1) {
            pq.push({v, nums2.begin()});
        }
        
        for (int i = 0; i < k && !pq.empty(); i++) {
            auto ele = pq.top();
            pq.pop();
            res.push_back({ele.first, *(ele.second)});
            ele.second++;
            if (ele.second != nums2.end()) {
                pq.push({ele.first, ele.second});
            }
        }
        
        return res;
    }
};
