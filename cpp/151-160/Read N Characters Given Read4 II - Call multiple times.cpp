// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    
    char buf4[4];
    int i4 = 0, n4 = 0;
    
public:

    int read(char *buf, int n) {
        int i = 0;
        while (i < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buf4))))
            buf[i++] = buf4[i4++];
        return i;
    }
};
