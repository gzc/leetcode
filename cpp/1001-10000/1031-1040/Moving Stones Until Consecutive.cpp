class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v{a,b,c};
        sort(v.begin(), v.end());
        int maximum_move = v[2] - v[0] - 2;
        
        int d1 = v[1] - v[0];
        int d2 = v[2] - v[1];
        
        int minimum_move = 0;
        
        if (d1 == 1 && d2 == 1) return {0, maximum_move};
        if (d1 == 1 || d2 == 1 || d1 == 2 || d2 == 2) return {1, maximum_move};
        
        return {2, maximum_move};
    }
};
