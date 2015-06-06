#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int n(x), base(0),rbase(1);
        
        while(n > 0)
        {
            if(base == 0) base = 1;
            else base *= 10;
            n /= 10;
        }
        
        while(base > rbase)
        {
            if( (x / base - x / rbase) % 10 != 0) return false;
            base /= 10;
            rbase *= 10;
        }
        
        return true;
    }
    
};

int main()
{
    Solution s;
    
    cout << s.isPalindrome(1000000001);
}