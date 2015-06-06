/*************************************************************************
	> File Name: N-Queens.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Fri Apr 17 23:37:12 2015
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
    
    bool *cols;
    bool *add;
    bool *diff;
    int n;
    int sum;
    
    bool valid(int i, int j)
    {
        if(cols[j] == false && add[i+j] == false && diff[i-j+n] == false)
            return true;
        return false;
    }
    
    void help(int i, int j)
    {
        if(i == n)
        {
            sum++;
            return;
        } else {
            
            for(int k = 0;k < n;k++)
            {
                j = k;
                if(valid(i, j))
                {
                    cols[j] = true;
                    add[i+j] = true;
                    diff[i-j+n] = true;
                    help(i+1, 0);
                    cols[j] = false;
                    add[i+j] = false;
                    diff[i-j+n] = false;
                }
            }
            return;
        }
    }
    
public:
    int totalNQueens(int n) {
        
        cols = new bool[n];
        add = new bool[2*n];
        diff = new bool[2*n];
        memset(cols, false, n);
        memset(add, false, 2*n);
        memset(diff, false, 2*n);
        this->n = n;
        sum = 0;
        help(0, 0);
        
        return sum;
    }
    
};

int main() {
    Solution s;
    cout << s.totalNQueens(4);


    return 0;
}
