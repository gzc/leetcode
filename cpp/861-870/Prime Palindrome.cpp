class Solution {
public:
    int primePalindrome(int N) {
        if (N == 1 || N == 2) return 2;
        if (N % 2 == 0) N++;
        long t, r = 0, d;
 
        while (true) {
            t = N;

            while(t) {
              r = r * 10; 
              r = r + t % 10;
              t = t / 10;
            }

            if (r == N) {
              d = (int)sqrt(N);
              long c = 2;
              for (; c <= d; c++) {
                if (N % c == 0) break;
              }
              if (c == d + 1)
                break;
            }
            
            r = 0;
            N += 2;
        }
        
        return N;
    }
};
