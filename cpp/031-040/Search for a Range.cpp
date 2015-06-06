#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        
        int left = 0;
        int right = n-1;
        vector<int>result;
        
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(target < A[mid])
                right = mid-1;
            else if(target > A[mid])
                left = mid+1;
            else
            {
                int l(mid),r(mid);
                while(l > 0 && A[l] == A[l-1]) l--;
                while(r < n-1 && A[r] == A[r+1]) r++;
                result.push_back(l);
                result.push_back(r);
                return result;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    
};

int main()
{
    Solution s;
    int a[] = {5, 7, 7, 8, 8, 10};

    vector<int>v = s.searchRange(a, 6, 8);
    cout << v[0] << " " << v[1];
    return 0;
}