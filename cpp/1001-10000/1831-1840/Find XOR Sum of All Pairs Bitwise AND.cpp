class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> bits(32, 0);
        for (int v : arr2) {
            int pos = 0;
            while (v > 0) {
                if (v & 1) {
                    bits[pos]++;
                }
                v = v >> 1;
                pos++;
            }
        }
        
        int res = 0;
        
        for (int v : arr1) {
            int pos = 0;
            int tmp = 0;
            while (v > 0) {
                if (v & 1) {
                    if (bits[pos] % 2 == 1) {
                        tmp |= (1 << pos);
                    }
                }
                v = v >> 1;
                pos++;
            }
            
            res ^= tmp;
        }
        
        return res;
    }
};
