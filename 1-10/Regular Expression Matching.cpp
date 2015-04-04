#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        if(*s == 0 && *p == 0) return true;
        if(*s != 0 && *p == 0) return false;
        
        if(*p == '.')
        {
            if(*(p+1) == '*')
            {
                if(*s == 0) return isMatch(s, p+2);
                else return isMatch(s+1, p) || isMatch(s, p+2);
            }
            else if(*s == 0) return false;
            else return isMatch(s+1, p+1);
        }
        else
        {
            if(*(p+1) == '*' && *s == *p)
                return isMatch(s, p+2) || isMatch(s+1, p);
            else if(*(p+1) == '*' && *s != *p)
                return isMatch(s, p+2);
            else if(*s != *p) return false;
            else return isMatch(s+1, p+1);
        }
        
    }
    
};

int main()
{
    Solution s;
    
    cout << s.isMatch("a", ".*..a*");
}