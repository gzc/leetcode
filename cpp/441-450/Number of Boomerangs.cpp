class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
    
        // iterate over all the points
        for (int i = 0; i < points.size(); ++i) {

            unordered_map<long, int> group;

            // iterate over all points other than points[i]
            for (int j = 0; j < points.size(); ++j) {

                if (j == i) continue;

                int dy = points[i].second - points[j].second;
                int dx = points[i].first - points[j].first;

                // compute squared euclidean distance from points[i]
                int key = dy * dy + dx * dx;

                // accumulate # of such "j"s that are "key" distance from "i"
                ++group[key];
            }

            for (auto& p : group) {
                if (p.second > 1) {
                    /*
                     * for all the groups of points, 
                     * number of ways to select 2 from n = 
                     * nP2 = n!/(n - 2)! = n * (n - 1)
                     */
                    res += p.second * (p.second - 1);
                }
            }
        }

        return res;
    }
};
