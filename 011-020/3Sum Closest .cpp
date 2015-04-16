#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        int r(0), diff(INT_MAX);
        
        sort(num.begin(), num.end());
        
        int i(0),j(0),k(0);
        
        for(;i < num.size()-2;)
        {
            j = i + 1;
            k = num.size()-1;
            int remain = target - num[i];
            
            while(j < k)
            {
                int tmp = abs(num[j] + num[k] - remain);
                if(tmp < diff)
                {
                    diff = tmp;
                    r = num[i] + num[j] + num[k];
                }
                
                if(num[j] + num[k] > remain) k--;
                else j++;
            }
            
            do{
                i++;
            }
            while(num[i] == num[i-1]);
        }
        return r;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 1, 1, 0};
    vector<int> v(a, a+4);
    cout << s.threeSumClosest(v, 100);
    
    return 0;
}