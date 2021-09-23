class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.size() <= 2) {
            return points.size();
        }
        
        int maxNum = 0;
        
        for (int i = 0; i < points.size(); i++) {
            int localmax = 0, overlap = 0;
            map<pair<int, int>, int> statistic;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) {
                    overlap++;
                    continue;
                } else {
                    int x = points[j][0] - points[i][0];
                    int y = points[j][1] - points[i][1];
                    int divide = __gcd(x,y);
                    x /= divide;
                    y /= divide;
                    pair<int, int>p(x,y);
                    statistic[p]++;
                    localmax = max(statistic[p], localmax);
                }
            }
            maxNum=max(maxNum, localmax + overlap + 1);
        }
        
        return maxNum;
    }
};
