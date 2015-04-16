#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        
        if(n == 0) return 0;
        if(target < A[0]) return 0;
        
        for(int i = 0;i < n;i++)
        {
            if(A[i] == target) return i;
            if(A[i] < target && A[i+1] > target) return i+1;
        }
        return n;
        
    }
    
};

int main()
{
    Solution s;
    int a[] = {5, 7, 8, 10};

    cout << s.searchInsert(a, 4, 7);
    return 0;
}