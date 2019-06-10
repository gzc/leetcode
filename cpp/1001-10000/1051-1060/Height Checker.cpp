class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int returned_ans = 0;
        vector<int> copy = heights;
        sort(begin(heights), end(heights));
        for (int i = 0; i < heights.size(); i++) {
            returned_ans += (heights[i] != copy[i]);
        }
        return returned_ans;
    }
};
