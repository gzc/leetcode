#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int r = 0;
        
        while(n > 0)
        {
            n = n & (n-1);
            r++;
        }
        
        return r;
    }
    
};

int main()
{
    Solution s;
    
    cout << s.hammingWeight(11);
}