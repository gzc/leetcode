class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int maxGap = 0;
        for (int i = 1; i < stations.size(); i++) {
            maxGap = max(maxGap, stations[i] - stations[i-1]);
        }
        
        double lower = 0, upper = maxGap;
        while (upper - lower >= 1e-6) {
            double mid = (lower + upper) / 2;
            int num = 0;
            for (int i = 1; i < stations.size(); i++) {
                num += ceil((stations[i] - stations[i-1]) / mid) - 1;
            }
            if (num > K) {
                lower = mid;
            } else {
                upper = mid;
            }
        }
        
        return upper;
    }
};
