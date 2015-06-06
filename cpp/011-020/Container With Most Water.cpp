#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        
        int area(0),i(0),j(height.size()-1);
        
        while(i < j)
        {
            int l = height[i];
            int r = height[j];
            area = max(area, (j-i)*min(l, r));
            
            if(l <= r)
                while(height[i] <= l && i < j)
                    i++;
            else
                while(height[j] <= r && i < j)
                    j--;
        }
        
        return area;
    }
    
};

int main()
{
    Solution s;
    int a[2] = {1,2};
    vector<int>v (a, a+2);
    
    cout << s.maxArea(v);
}