class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mymap;
        for (int num : nums) {
            mymap[num]++;
        }
        
        int result = 0;
        for (auto it : mymap) {
            if (mymap.count(it.first+1)) {
                result = max(result, mymap[it.first + 1] + mymap[it.first]);
            }
        }
        return result;
    }
};
