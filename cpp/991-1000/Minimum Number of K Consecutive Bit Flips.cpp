class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0;
        int flag = 0;
        map<int, int> mymap;
        
        for (int i = 0; i < A.size(); i++) {
            flag ^= mymap[i];
            
            if (A[i] + flag == 1) continue;
            
            // flip
            ans++;
            flag = 1 - flag;
            
            if (i + K > A.size()) return -1;
            
            mymap[i+K] = 1 - mymap[i+K];
        }
        
        return ans;
    }
};
    
