#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    
    int BF_match(char *text,char *pattern)
    {
        size_t n = strlen(text);
        size_t m = strlen(pattern);
        int i;
        int end = n-m;
        
        for(i = 0; i <= end; i++)
        {
            int j;
            char *p_text = text + i;
            for(j = 0;j < m;j++)
            {
                if(*(p_text+j) == *(pattern+j))
                    continue;
                else
                    break;
            }
            if(j == m)
                return i;
        }
        return -1;
    }
    
    int strStr(char *haystack, char *needle) {
        return BF_match(haystack, needle);
    }
    
};

int main()
{
    Solution s;

    cout << s.BF_match("hddskah", "ska");
    
    return 0;
}