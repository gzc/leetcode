class Solution {
public:
    int findComplement(int num) {
        int mask = 0xffffffff;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
