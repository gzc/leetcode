class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        
        int res = -1;
        
        for (int i = 0; i < houses.size(); i++) {
            
            auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            
            int tmp = INT_MAX;
            
            if (it != heaters.end()) tmp = *it - houses[i];
            
            if (it != heaters.begin()) tmp = min(tmp, houses[i] - *(it-1));
            
            res = max(res, tmp);
        }
        
        return res;
    }
};
