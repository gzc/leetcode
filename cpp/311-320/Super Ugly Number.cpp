class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int>index(k, 0);
        vector<int>v(n,INT_MAX);
        v[0] = 1;
        int val = 1;
        
        for(int i=1; i<n; i++){
            for(int j = 0; j< k; j++) v[i] = min(v[i],v[index[j]]*primes[j]);
            for(int j = 0; j< k; j++) index[j] += (v[i]==v[index[j]]*primes[j]);
        }
        return v[n-1];
    }
};