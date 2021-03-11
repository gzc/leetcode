class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map<int, int> mymap;
        int res = INT_MIN;
        int sum = 0;
        for (int beauty : flowers) {
            if (mymap.count(beauty) > 0) {
                res = max(res, sum - mymap[beauty] + 2 * beauty);
            }
            
            if (beauty > 0) {
                sum += beauty;
            }
            
            if (mymap.count(beauty) == 0) {
                mymap[beauty] = sum;
            }
        }
        
        return res;
    }
};
