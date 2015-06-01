class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        if(nums.size() < 2 || k < 0) return false;
        
        deque<int> dq;
        multiset<long> window;
        
        for(auto e : nums)
        {
            if(dq.size() > k)
            {
                int item = dq.front();
                dq.pop_front();
                window.erase(window.find(item));
            }
            
            auto it = window.lower_bound((long)e - (long)t);
            if(it == window.end() || (*it) > ((long)e + (long)t))
            {
                dq.push_back(e);
                window.insert(e);
            }
            else return true;
        }
        return false;
    }
};
