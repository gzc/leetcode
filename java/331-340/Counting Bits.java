/*
 * 0000 0001 0010 0011 0100 0101 0110 0111 1000
 *  0     1    1   2     1    2    2    3    1
 */
public class Solution {
    public int[] countBits(int num) {
        int[] result = new int[num+1];
        if(num == 0) return result;
        
        int loops = 1;
        
        while(true) {
            for(int k = 0;k < loops;k++) {
                int index = k+loops;
                if(index > num)
                    return result;
                result[index] = result[k]+1;
            }
            loops *= 2;
        }
    }
}