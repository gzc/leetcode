// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    
    queue<char> buffer;
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        int len = 0;
        
        while(buffer.size() > 0)
        {
            *buf = buffer.front();
            buffer.pop();
            buf++;
            len++;
            if(n == len){
                return len;
            }
        }
        
        while(len < n)
        {
            int v = read4(buf);
            if(v == 0) return len;
            len += v;
            buf += v;
        }
        
        int diff = len - n;
        for(char *temp = buf - diff; temp != buf; temp++)
            buffer.push(*temp);
        buf = buf - diff;
        *buf = '\0';
        return n;
    }
};