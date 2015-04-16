#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size() < 2) return 0;
        
        int count(0);
        int step(0);
        int nextstep(0);
        
        for(int i = 0;i < nums.size();i++)
        {
            if(i + nums[i] > nextstep) nextstep = i + nums[i];
            if(i == step && i != nums.size()-1) {
                step = nextstep;
                count++;
            }
        }
        
        return count;
        
    }
    
};

int main()
{
    Solution s;
    int a[] = {1,2,3};
    vector<int>v{a, a+3};
    cout << s.jump(v);
    return 0;
}