class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> mymap;
        for (int e : hand) mymap[e]++;
        
        while (!mymap.empty()) {
            int small = (mymap.begin())->first;
            for (int i = 0; i < W; i++) {
                if (mymap[small] > 0) {
                    mymap[small]--;
                    if (mymap[small] == 0) {
                        mymap.erase(small);
                    }
                } else {
                    return false;
                }
                small++;
            }
        }
        
        return true;
    }
};
