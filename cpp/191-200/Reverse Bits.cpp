#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t r(0);
        
        for(int i = 0;i < 32;i++)
            r += ((n >> i) & 1) * (1 << (31-i));
        
        return r;
    }
    
};

int main()
{
    Solution s;
    
    cout << s.reverseBits(43261596);
}