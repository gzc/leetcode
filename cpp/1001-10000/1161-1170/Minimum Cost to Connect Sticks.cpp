class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, std::greater<int>> myqueue;
        for (int e : sticks) myqueue.push(e);
        
        int ans = 0;
        
        while (myqueue.size() > 1) {
            int e1 = myqueue.top(); myqueue.pop();
            int e2 = myqueue.top(); myqueue.pop();
            ans += (e1 + e2);
            myqueue.push(e1 + e2);
        }
        
        return ans;
    }
};
