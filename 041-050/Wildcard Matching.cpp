#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        int i(0),j(0),ss(0),pp(-1);
        
        while(i < s.length())
        {
            if(s[i] == p[j] || p[j] == '?') {i++;j++;continue;}
            
            else if(p[j] == '*'){ss = i;pp = ++j;continue;}
            
            else if(pp != -1) {i = ++ss;j = pp;continue;}
            
            return false;
        }
        
        while(j < p.length()) if(p[j++] != '*') return false;
        return true;
    }
    
};

int main()
{
    Solution s;
    cout << s.isMatch("ab", "?*");

    return 0;
}