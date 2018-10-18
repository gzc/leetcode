class Solution {
    
    long MOD = 1000000007;
    
    long getCount(int a, int b, int c, unordered_map<int, int>& mymap) {
        long v = 0;
        long ta = mymap[a];
        long tb = mymap[b];
        long tc = mymap[c];
        if (a == b && b == c) {
            v = ta*(ta-1)*(ta-2)/6;
        } else if (a == b) {
            v = tc*tb*(tb-1)/2;
        } else if (b == c) {
            v = ta*tb*(tb-1)/2;
        } else {
            v = ta*tb*tc;
        }
        return v%MOD;
    }
    
public:
    int threeSumMulti(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        unordered_map<int, int> mymap;
        for (int e : A) mymap[e]++;
        long ans = 0;
        
        for (int i = 0; i < A.size(); i++) {
            if (3*A[i] > target) break;
            while (i > 0 && i < A.size() && A[i] == A[i-1]) i++;
            for (int j = i + 1; j < A.size(); j++) {
                while (j < A.size() && A[j] != A[i] && A[j] == A[j-1]) j++;
                while (j > 1 && j < A.size() && A[j] == A[j-2]) j++;
                if (j >= A.size()-1) break;
                if (2*A[j] > target - A[i]) break;
                int v = target - A[i] - A[j];
                if (mymap.count(v) > 0) {
                    ans = (ans + getCount(A[i], A[j], v, mymap)) % MOD;
                }
                
            }
        }
        
        return ans;
    }
};
