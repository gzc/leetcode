class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, std::greater<int>> myqueue;
        for (int i = 0; i < heights.size() - 1; i++) {
            if (heights[i+1] > heights[i]) {
                myqueue.push(heights[i+1] - heights[i]);
            }
            
            if (myqueue.size() > ladders) {
                int h = myqueue.top();
                myqueue.pop();
                bricks -= h;
                if (bricks < 0) return i;
            }
        }
        
        return heights.size() - 1;
    }
};
