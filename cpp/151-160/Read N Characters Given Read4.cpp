// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        int hasread(0);
        int nn = n;
        
        while(n > 0) {
            int temp = read4(buf);
            if(temp == 0) break;
            hasread += temp;
            n -= temp;
            buf += temp;
        }
        
        return min(hasread, nn);
    }
};
