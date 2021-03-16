class Solution {
private:
    char cache[4];
    int cache_ind = 0;
    int cache_cnt = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ind = 0;
        while (true) {
            while (cache_cnt > 0 && ind < n) {
                buf[ind] = cache[cache_ind];
                ind++;
                cache_ind++;
                cache_cnt--;
            }
            if (ind == n) {
                return ind;
            }
            cache_ind = 0;
            cache_cnt = read4(cache);
            if (cache_cnt == 0) {
                break;
            }
        }
        return ind;
    }
};
