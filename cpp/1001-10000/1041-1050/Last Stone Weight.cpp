class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, std::vector<int>, std::less<int> >
                            myqueue (stones.begin(), stones.end());
        while (myqueue.size() > 1) {
            int v1 = myqueue.top();
            myqueue.pop();
            int v2 = myqueue.top();
            myqueue.pop();
            int v = abs(v1 - v2);
            if (v > 0) myqueue.push(v);
        }
        
        return myqueue.empty() ? 0 : myqueue.top();
    }
};
