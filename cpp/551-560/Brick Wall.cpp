class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> mymap; // pos -> count
        int maxCount = 0;
            
        for (const vector<int>& wal : wall) {
            int sum = 0;
            for (int i = 0; i < wal.size() - 1; i++) {
                sum += wal[i];
                mymap[sum]++;
                maxCount = max(maxCount, mymap[sum]);
            }
        }
        
        return wall.size() - maxCount;
    }
};
