class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mymap;
        
        int ans = 0;
        for (int e : answers) {
            if (mymap.count(e) == 0 || mymap[e] == 0) {
                ans += (e+1);
                mymap[e] = e;
            } else {
                mymap[e]--;
            }
        }
        
        return ans;
    }
};
