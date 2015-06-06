#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        
        int len(0);
        string r("");
        
        if(strs.size() == 0) return r;
        
        for(;;)
        {
            char ch;
            if(len == strs[0].length()) return r;
            else ch = strs[0][len];
            for(int i = 1;i < strs.size();i++)
            {
                if(len+1 > strs[i].length())
                    return r;
                if(strs[i][len] != ch)
                    return r;
            }
            r += ch;
            len++;
        }
        
        return r;
    }
    
};

int main()
{
    Solution s;
    vector<string> v;
    v.push_back("aaa");
    v.push_back("ab");
    s.longestCommonPrefix(v);
    
    return 0;
}