class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        map<int, int> mymap;
        for (int i = 1; i <= N; i++) mymap[i] = 0;
        for (const auto& e : trust) {
            mymap[e[0]]--;
            mymap[e[1]]++;
        }
        
        for (const auto& iter : mymap) {
            if (iter.second == N - 1) return iter.first;
        }
        
        return -1;
    }
};
