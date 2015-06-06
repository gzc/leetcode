#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int *p = new int[s.size()];
        memset(p, 0, sizeof(int)*s.size());
        stack<pair<char, int> >_stack;
        
        for(int i = 0;i < s.size();i++)
        {
            char c = s[i];
            if(_stack.empty()) _stack.push(make_pair(c, i));
            else {
                if(c == '(') _stack.push(make_pair(c, i));
                else if(_stack.top().first == '(') {
                    pair<char, int> tmp = _stack.top();
                    _stack.pop();
                    p[tmp.second] = 1;
                    p[i] = 1;
                }
            }
        }
        
        int r(0);
        for(int i = 1;i < s.size();i++)
        {
            if(p[i] > 0)
                p[i] = p[i]+p[i-1];
            r = max(r, p[i]);
        }
        
        return r;
        
    }
    
    
};

int main()
{
    Solution s;

    cout << s.longestValidParentheses("(()");
    return 0;
}