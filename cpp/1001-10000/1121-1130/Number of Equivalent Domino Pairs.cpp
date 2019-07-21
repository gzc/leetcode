class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mymap;
        for (const vector<int>& domi : dominoes) {
            mymap[{min(domi[0], domi[1]), max(domi[0], domi[1])}]++;
        }
        
        int ans = 0;
        for (auto it : mymap) {
            if (it.second > 0) {
                ans += it.second * (it.second-1) / 2;
            }
        }
        return ans;
    }
};
