class Solution {
public:
    int largestRectangleArea(vector<int> &hist) {
        int res(0);
        stack<int> s;
        hist.push_back(0);
        for (int i = 0;i < hist.size();i++) {
            while (!s.empty() && hist[i] < hist[s.top()]) {
                int tp = s.top();
                int h = hist[tp];
                s.pop();
            
                int tmp = h * (s.empty() ? i : i-s.top()-1);
                res = max(res, tmp);
            }
            s.push(i);
        }
        return res;
    }
};
