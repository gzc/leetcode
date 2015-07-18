class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> myqueue;
        vector<int> res;
        
        for(int i = 0;i < nums.size();i++){
            if(!myqueue.empty() && myqueue.front() == i - k) myqueue.pop_front();
            while(!myqueue.empty() && nums[myqueue.back()] < nums[i]) myqueue.pop_back();
            myqueue.push_back(i);
            if(i >= k - 1) res.push_back(nums[myqueue.front()]);
        }
        
        return res;
    }
};