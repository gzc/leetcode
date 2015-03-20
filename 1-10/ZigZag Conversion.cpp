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
    string convert(string s, int nRows) {
        string v[nRows];
        int k(0), up(1);
        for(size_t i = 0;i < s.size();i++) {
            v[k] = v[k] + s[i];
            k += up;
            if(k == (nRows-1) ) up = -1;
            else if(k == 0) up = 1;
            if(k == nRows) k = 0;
        }
        string res("");
        for(int i = 0;i < nRows;i++)
            res += v[i];
        return res;
    }
    
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3);
    
    return 0;
}