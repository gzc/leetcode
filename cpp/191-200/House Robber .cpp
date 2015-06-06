#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */

class Solution {
public:
    int rob(vector<int> &num) {
        
        if(num.size() == 0) return 0;
        else if(num.size() == 1) return num[0];
        
        int p[num.size()];
        p[0] = num[0];
        p[1] = max(num[0], num[1]);
        
        for(int i = 2;i < num.size();i++)
            p[i] = max(p[i-2] + num[i], p[i-1]);
        
        return p[num.size()-1];
    }
    
    
};

int main()
{
    Solution s;
    int a[5] = {3,7,2,100,4};
    vector<int> num(a, a+5);
    cout << s.rob(num);
    
    
    return 0;
}