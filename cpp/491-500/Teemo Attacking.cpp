class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int begin = timeSeries[0], result = 0;
        for (int v : timeSeries) {
            result += begin + duration >= v ? v - begin : duration;
            begin = v;
        }
        return result + duration;
    }
};
