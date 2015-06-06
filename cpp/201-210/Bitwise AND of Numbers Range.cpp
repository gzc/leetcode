#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        if(m == 0) return 0;
        
        int m_maxbit(0), n_maxbit(0);
        int tmp(n);
        while(tmp > 0)
        {
            tmp = tmp >> 1;
            if(n_maxbit == 0) n_maxbit = 1;
            else n_maxbit *= 2;
        }
        tmp = m;
        while(tmp > 0)
        {
            tmp = tmp >> 1;
            if(m_maxbit == 0) m_maxbit = 1;
            else m_maxbit *= 2;
        }
        if(m_maxbit != n_maxbit) return 0;
        return m_maxbit + rangeBitwiseAnd(m - m_maxbit, n - n_maxbit);
    }
    
};

int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7);

    return 0;
}