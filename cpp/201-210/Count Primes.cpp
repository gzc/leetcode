#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        
        if(n < 3) return 0;
        
        int limit = sqrt(n);
        int r(n-2);
        
        bool *A = new bool[n+1];
        memset(A, true, n+1);
        
        
        for(int i = 2;i <= limit;i++)
        {
            if(A[i] == true)
            {
                for(int j = i*i;j < n;j += i)
                {
                    if(A[j] == true) r--;
                    A[j] = false;
                }
            }
            
        }
        return r;
    }
};

int main()
{
    Solution s;
    cout << s.countPrimes(2);
}