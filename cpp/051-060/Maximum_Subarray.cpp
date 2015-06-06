/*************************************************************************
	> File Name: Maximum_Subarray.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sat Apr 18 19:14:47 2015
 ************************************************************************/
#include<iostream>
#include<cstdio>
#include<list>
#include<vector>
#include<unordered_map>
#include<climits>
#include<unordered_set>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int maxSubArray(std::vector<int>& A) {
        int n = A.size();
        int a1(0), a2(0);
        int m = INT_MIN;
        
        for(int i = 0;i < n;i++)
        {
            if(i == 0) a2 = A[i];
            else if (a1 < 0) a2 = A[i];
            else a2 = A[i]+a1;
            m = max(m,a2);
            a1 = a2;
        }
        
        return m;
    }
};


int main() {
    Solution s;


    return 0;
}
