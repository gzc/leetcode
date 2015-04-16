#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        
        int now = A[0];
        int index = 0;
        int trap = 0;
        
        for(int i = 1;i < n;i++)
        {
            if(A[i] > now)
            {
                now = A[i];
                index = i;
            }
            else if(A[i] <= now)
            {
                trap += now-A[i];
            }
        }
        int tmp = now;
        
        
        now = A[n-1];
        for(int i = n-1;i > index;i--)
        {
            trap = trap - tmp+A[i];
            if(A[i] > now)
            {
                now = A[i];
            }
            else if(A[i] <= now)
            {
                trap += now-A[i];
            }
        }
        
        return trap;
    }
    
};

int main()
{
    Solution s;
    int a[] = {9,6,8,8,5,6,3};
    cout << s.trap(a, 7);

    return 0;
}