/*
 * 0000 0001 0010 0011 0100 0101 0110 0111 1000
 *  0     1    1   2     1    2    2    3    1
 */

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> myvec(num+1, 0);
        if(num == 0) return myvec;
        
        int loops = 1;
        while(1) {
            
            int _size = loops;
            for(int k = 0;k < loops;k++) {
                int index = k+_size;
                if(index > num)
                    return myvec;
                myvec[index] = myvec[k]+1;
            }
            loops *= 2;
        }
        
    }
};