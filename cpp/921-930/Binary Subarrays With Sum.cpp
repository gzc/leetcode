class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> mymap;
        int sum = 0;
        int ans = 0;
        mymap[0] = -1;
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            if (A[i] == 1) mymap[sum] = i;
            
            if (sum >= S) {
                int needed = sum - S;
                int idx2 = mymap.count(needed+1) == 0 ? i : mymap[needed+1];
                int idx1 = mymap[needed];
                ans += (idx2 - idx1);
            }
        }
        
        return ans;
    }
};
