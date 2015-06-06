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
    
    vector<string> r;
    
    void help(string s, int n, int m)
    {
        if(m < n) return;
        
        if(n == 0)
        {
            for(int i = 0;i < m;i++)
                s += ")";
            r.push_back(s);
        }
        
        else
        {
            if(m == n) help(s+"(", n-1, m);
            else
            {
                help(s+"(", n-1, m);
                help(s+")", n, m-1);
            }
        }
    }
    
    
public:
    vector<string> generateParenthesis(int n) {
        
        help("", n, n);
        return r;
    }
};

int main()
{
    Solution s;
    
    vector<string>v = s.generateParenthesis(3);
    
    for(int i = 0;i < v.size();i++)
    {
        cout << v[i] << endl;
    }
    cout << v.size();
    
    
    return 0;
}