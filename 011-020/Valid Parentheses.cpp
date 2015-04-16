#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> container;
        
        for(int i = 0;i < s.length();i++)
        {
            if(container.empty())
                container.push(s[i]);
            else
            {
                char c = s[i];
                char v = container.top();
                if(c == '(' || c == '{' || c == '[')
                    container.push(c);
                else
                {
                    if( (c == ')' && v == '(') || (c == '}' && v == '{') || (c == ']' && v == '['))
                        container.pop();
                    else
                        return false;
                }
            }
        }
        
        if(container.empty())
            return true;
        
        return false;
    }
    
};

int main()
{
    Solution s;
    cout << s.isValid("({})");
    
    
    return 0;
}