class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mymap;
        for (int e : deck) mymap[e]++;
        int gcd = mymap[deck[0]];
        for (const auto& e : mymap) gcd = __gcd(gcd, e.second);
        return gcd >= 2;
    }
};w
