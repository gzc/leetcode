// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int n = 7 * rand7() + rand7() - 8;
            if (n < 40) return n % 10 + 1;
        }
    }
};
