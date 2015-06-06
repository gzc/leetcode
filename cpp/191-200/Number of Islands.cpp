#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    
    size_t M;
    size_t N;
    
    bool valid(int i, int j)
    {
        if(i >= 0 && j >= 0 && i < M && j < N) return true;
        return false;
    }
    
    void mark(vector<vector<char>> &grid, int i, int j)
    {
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        if(valid(i+1,j)) mark(grid, i+1, j);
        if(valid(i-1,j)) mark(grid, i-1, j);
        if(valid(i,j+1)) mark(grid, i, j+1);
        if(valid(i,j-1)) mark(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>> &grid) {
        
        int r(0);
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        M = grid.size();
        N = grid[0].size();
        
        for(int i = 0;i < M;i++)
        {
            for(int j = 0;j < N;j++)
            {
                
                if(grid[i][j] == '1')
                {
                    r++;
                    mark(grid, i, j);
                } else {
                    continue;
                }
            }
        }
        
        return r;
        
    }
    
};

int main()
{
    Solution s;
    vector<vector<char>> v;
    char a1[] = {'1','1','0','0','0'};
    char a2[] = {'0','0','1','0','0'};
    char a3[] = {'0','0','0','1','1'};
    vector<char> v1(a1, a1+5);
    vector<char> v2(a1, a1+5);
    vector<char> v3(a2, a2+5);
    vector<char> v4(a3, a3+5);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    cout << s.numIslands(v);
    
    return 0;
}