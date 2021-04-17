class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (const vector<int>& query : queries) {
            int num = 0;
            int threshold = query[2] * query[2];
            for (const vector<int>& point : points) {
                int dis_square = (point[0] - query[0]) * (point[0] - query[0]) + (point[1] - query[1]) * (point[1] - query[1]);
                if (dis_square <= threshold) {
                    num++;
                }
            }
            ans.push_back(num);
        }
        
        return ans;
    }
};
