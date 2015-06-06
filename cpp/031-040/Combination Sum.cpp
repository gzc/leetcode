#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    
    void help(vector<int>& now, vector<int>&candidates, int index, int target, vector<vector<int>>& results)
    {
        for(int i = index;i < candidates.size();i++)
        {
            if(candidates[i] < target)
            {
                now.push_back(candidates[i]);
                help(now, candidates, i, target-candidates[i], results);
                now.pop_back();
            } else if(candidates[i] == target) {
                now.push_back(candidates[i]);
                results.push_back(now);
                now.pop_back();
            }
        }
        
    }
    
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        vector<vector<int>> results;
        vector<int>tmp;
        sort(candidates.begin(), candidates.end());
        help(tmp, candidates, 0, target, results);
        
        return results;
        
    }
    
};

int main()
{
    Solution s;

    return 0;
}