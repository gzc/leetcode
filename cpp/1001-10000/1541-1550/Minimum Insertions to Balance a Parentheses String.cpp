class Solution {
public:
   int minInsertions(string s) {
       int res = 0;
       int close_needed = 0;
       
       
       for (int i = 0; i < s.length(); i++) {
           
           if (s[i] == '(') {
               if (close_needed % 2 == 1) {
                   // Handle previous case like '()('
                   res++;
                   close_needed--;
               }
               close_needed += 2; // Add 2 required close for current '('
           } else {
               if (close_needed == 0) {
                   res++;
                   close_needed++;
               } else {
                   close_needed--;
               }
           }
           
       }
       
       return res + close_needed;
   }
};
