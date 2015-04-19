#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int lastLength = 0;
        
        while(*s != '\0')
        {
            if(*s == ' ' && *(s+1) != '\0' && *(s+1) != ' ')
                lastLength = 0;
            else if(*s != ' ')
                lastLength++;
            
            s++;
        }
        
        return lastLength;
    }
    
};

int main()
{
    Solution s;
    
    return 0;
}