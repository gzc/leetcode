#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
    
    int help(int n)
    {
        int r(0);
        while(n > 0)
        {
            int tmp = n%10;
            n = (n - tmp)/10;
            r += tmp*tmp;
        }
        return r;
    }
    
public:
    bool isHappy(int n) {
        
        set<int> _set;
        
        while(1)
        {
            if(_set.count(n) == 1)
                return false;
            if(n == 1) return true;
            _set.insert(n);
            n = help(n);
        }
        return false;
    }
    
};

int main()
{
    Solution s;
    cout << s.isHappy(33);
    
    return 0;
}