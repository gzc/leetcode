#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        
        int i(0),j(n-1);
        
        while(i <= j)
        {
            if(A[i] == elem)
            {
                swap(A[i], A[j]);
                j--;
            }
            if(A[i] != elem) i++;
        }
        
        return j+1;
    }
    
};

int main()
{
    Solution s;
    
    int a[3] = {1,1,1};
    int c = s.removeElement(a, 3, 1);
    cout << c;
    
    return 0;
}