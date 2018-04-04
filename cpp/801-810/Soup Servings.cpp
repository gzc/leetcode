class Solution {
    
    double dfs(int A, int B, map<pair<int, int>, double>& mymap) {
        if (A <= 0 && B > 0) return 1;
        if (A <= 0 && B <= 0) return 0.5;
        if (B <= 0) return 0;
        
        pair<int, int> mypair = make_pair(A, B);
        if (mymap.count(mypair)) {
            return mymap[mypair];
        }
        
        double res = 0.25 * (dfs(A-4, B, mymap) + dfs(A-3, B-1, mymap) + dfs(A-2, B-2, mymap) + dfs(A-1, B-3, mymap));
        return mymap[mypair] = res;
    }
    
public:
    double soupServings(int N) {
        N = (N + 24)/25;
        if (N >= 200) return 1.0;
        map<pair<int, int>, double> mymap;
        return dfs(N, N, mymap);
    }
};
