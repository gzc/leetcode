#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    
    void help(vector<int> v, vector<vector<int>>& result, int n, vector<int> num)
    {
        if(v.size() == n) {
            result.push_back(v);
            return;
        }
        
        int i = 0;
        int j = num.size();
        while(i < j)
        {
            int tmp = num[i];
            v.push_back(num[i]);
            num.erase(num.begin()+i);
            help(v, result, n, num);
            num.insert(num.begin()+i, tmp);
            v.pop_back();
            while(i < j && num[i] == tmp) i++;
        }
    }
    
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<int> v;
        vector<vector<int>> result;
        sort(num.begin(), num.end());
        help(v, result, num.size(), num);
        return result;
    }
    
};

int main()
{
    Solution s;
    int a[] = {1,2,3};
    
    return 0;
}