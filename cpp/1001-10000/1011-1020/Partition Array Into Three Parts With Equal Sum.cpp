class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int target = std::accumulate(A.begin(), A.end(), 0) / 3;
        
        int sum = 0;
        int times = 0;
        for (int e : A) {
            sum += e;
            if (sum == target) {
                times++;
                sum = 0;
            }
        }
        
        return times >= 3;
    }
};
