#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        if(n <= 1) return n;
        
        int cur(1), tmp(A[0]);
        
        for(int i = 1;i < n;i++)
        {
            if(A[i] == tmp) continue;
            
            A[cur] = A[i];
            cur++;
            tmp = A[i];
        }
        
        return cur;
    }
    
};

int main()
{
    Solution s;
    
    int a[3] = {1,1,1};
    int c = s.removeDuplicates(a, 3);
    for(int i = 0;i < c;i++) cout << a[i];
    
    return 0;
}