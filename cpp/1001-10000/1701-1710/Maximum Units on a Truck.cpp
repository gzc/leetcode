class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        auto cmp = [](const vector<int>& l, const vector<int>& r) {
            return l[1] > r[1];
        };
        
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int ans = 0;
        
        for (int i = 0; i < boxTypes.size(); i++) {
            
            if (truckSize <= 0) {
                break;
            }
            
            int num = boxTypes[i][0];
            int units = boxTypes[i][1];
            
            ans += min(num, truckSize) * units;
            truckSize = max(0, truckSize - num);
        }
        
        return ans;
    }
};
