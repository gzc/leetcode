#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxpos(0);

        for(int i = 0;i < nums.size();i++)
        {
            if(i <= maxpos)
            {
                int tmp = i + nums[i];
                if(tmp >= (nums.size()-1)) return true;
                maxpos = max(tmp, maxpos);
            }
            else return false;
        }
        return false;
    }
    
};

int main()
{
    Solution s;
    int a[] = {2,5,0,0};
    vector<int>v{a, a+4};
    cout << s.canJump(v);
    return 0;
}