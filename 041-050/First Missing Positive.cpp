#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        
        int i(0);
        
        while(i != n)
        {
            if(A[i] != i+1)
            {
                if(A[i] > 0 && A[i] <= n)
                {
                    if(A[i] != A[A[i]-1])
                    {
                        swap(A[i], A[A[i]-1]);
                        continue;
                    }
                }
            }
            i++;
        }
        
        for(int i = 0;i < n;i++)
            if(A[i] != i+1)
                return i+1;
        return A[n-1]+1;
        
    }
    
};

int main()
{
    Solution s;
    int a[] = {2,1};
    cout << s.firstMissingPositive(a, 2);

    return 0;
}