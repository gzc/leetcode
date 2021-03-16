/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    int read(char *buf, int n) {
        int ind = 0;
        while (ind < n) {
            char cache[4];
            int cache_cnt = read4(cache);
            if (cache_cnt == 0) {
                break;
            }
            int cache_ind = 0;
            while (cache_cnt > 0 && ind < n) {
                buf[ind] = cache[cache_ind];
                cache_ind++;
                ind++;
                cache_cnt--;
            }
        }
        return ind;
    }
};
