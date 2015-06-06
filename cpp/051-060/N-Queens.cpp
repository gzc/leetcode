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
    
    bool *rows;
    bool *cols;
    bool *add;
    bool *diff;
    unsigned int n;
    
    bool valid(int i, int j)
    {
        if(rows[i] == false && cols[j] == false && add[i+j] == false && diff[i-j+n] == false)
            return true;
        return false;
    }
    
    void help(vector<vector<string> > &result, vector<pair<int, int> > &tmp, int i, int j)
    {
        if(i == n)
        {
            if(n == tmp.size())
            {
                string s(n, '.');
                vector<string>t(n,s);
                for(int k = 0;k < tmp.size();k++)
                {
                    t[tmp[k].first][tmp[k].second] = 'Q';
                }
                result.push_back(t);
                return;
            } else {
                return;
            }
        } else {
            
            for(int k = 0;k < n;k++)
            {
                j = k;
                if(valid(i, j))
                {
                    rows[i] = true;
                    cols[j] = true;
                    add[i+j] = true;
                    diff[i-j+n] = true;
                    tmp.push_back(make_pair(i, j));
                    help(result, tmp, i+1, 0);
                    tmp.pop_back();
                    rows[i] = false;
                    cols[j] = false;
                    add[i+j] = false;
                    diff[i-j+n] = false;
                }
            }
            return;
        }
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        
        rows = new bool[n];
        cols = new bool[n];
        add = new bool[2*n];
        diff = new bool[2*n];
        this->n = n;
        
        vector<vector<string> > result;
        vector<pair<int, int> > tmp;
        
        help(result, tmp, 0, 0);
        
        return result;
        
    }
};

int main() {
    Solution s;
    vector<vector<string> > v = s.solveNQueens(4);
    for(int i = 0;i < v.size();i++)
    {
        vector<string>tmp = v[i];
        for(int j = 0;j < tmp.size();j++)
        {
            cout << tmp[j] << endl;
        }
        cout << endl << endl;
    }


    return 0;
}
