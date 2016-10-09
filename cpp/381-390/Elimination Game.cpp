/*
1 2 3 4 5 6 7 8 9
2 4 6 8(1 2 3 4)
*/

class Solution {
public:
    // https://discuss.leetcode.com/topic/58042/c-1-line-solution-with-explanation/2
    // After first elimination, all the rest numbers are even numbers.
    // Divide by 2, we get a continuous new sequence from 1 to n / 2.
    // For this sequence we start from right to left as the first elimination.
    // Then the original result should be two times the mirroring result of lastRemaining(n / 2).
    int lastRemaining(int n) {
        // Great answer. In fact, we can prove that "ML(1...n) + MR(1...n) = 1 + n" holds for any n >= 2, where ML(1...n) means removing elements from left to right first and MR(1...n) means removing elements from right to left first.
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};
