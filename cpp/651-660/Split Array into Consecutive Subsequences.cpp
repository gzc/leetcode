class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> mymap;
        for (int num : nums) mymap[num]++;
        while (true) {
            if (mymap.empty()) return true;
            pair<int, int> mypair = *mymap.begin();
            int temp = mypair.first;
            mymap[temp]--;
            int pick = 1;
            if (mymap[temp] == 0) mymap.erase(temp);
        
            while (true) {
                temp++;
                auto it = mymap.find(temp);
                if (pick < 3) {
                    if (it == mymap.end() || mymap[temp] == 0) return false;
                } else {
                    if (it == mymap.end()) break;
                    auto itt = mymap.find(temp-1);
                    int numm = 0;
                    if (itt != mymap.end()) numm = mymap[temp-1];
                    if (mymap[temp] == 0 || mymap[temp] <= numm) break;
                }
                mymap[temp]--;
                if (mymap[temp] == 0) mymap.erase(temp);
                pick++;
            }
            if (pick < 3) return false;
        }
    }
};
