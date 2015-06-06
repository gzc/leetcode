/*************************************************************************
	> File Name: Pow.cpp
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Fri Apr 17 16:40:27 2015
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
    double pow(double x, int n) {
        if(n == 0) return 1;
        double r(1);
        bool sign = (n >= 0);
        n = abs(n);
        while(n > 0)
        {
            if(n % 2 == 1)
                r *= x;
            x = x * x;
            n /= 2;
        }
        if(!sign) return 1.0/r;
        return r;
    }        
};


int main() {
    Solution s;
    double d;
    int n;
    cin >> d;cin >> n;
    cout << s.pow(d,n) << endl;


    return 0;
}
