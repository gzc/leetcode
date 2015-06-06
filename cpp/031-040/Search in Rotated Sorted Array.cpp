#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        
        int i(0),j(n-1);
        
        while(1)
        {
            int mid = (i+j)/2;
            if(A[mid] == target) return mid;
            if(i == j) return -1;
            if(i == mid)
            {
                i++;
                continue;
            }
            else if(A[mid] < A[i])
            {
                if(A[mid] < target && A[j] >= target) i = mid;
                else j = mid;
            } else {
                if(A[mid] > target && A[i] <= target) j = mid;
                else i = mid;
            }
        }
        
    }
    
};

int main()
{
    Solution s;
    int a[7] = {4,5,6,0,1,2,3};

    cout << s.search(a, 7, 2);
    return 0;
}