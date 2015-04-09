#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        
        vector<vector<int>>result;
        if(num.size() < 4) return result;
        
        sort(num.begin(), num.end());
        
        int buf1(INT_MAX),buf2(INT_MAX),buf3(INT_MAX),buf4(INT_MAX);
        
        for(int i = 0;i < num.size()-3;)
        {
            
            for(int j = i+1;j < num.size()-2;)
            {
                
                int l(j+1), r(num.size()-1);
                int remain = num[i] + num[j];
                
                while(l < r)
                {
                    int tmp = num[l] + num[r];
                    
                    if(tmp + remain == target)
                    {
                        int a[4] = {num[i], num[j], num[l], num[r]};
                        vector<int>v(a, a+4);
                        result.push_back(v);
                        do {l++;}while(l < r && num[l-1] == num[l]);
                        do {r--;}while(l < r && num[r+1] == num[r]);
                    }
                    else if(tmp + remain > target) do {r--;}while(l < r && num[r+1] == num[r]);
                    else do {l++;}while(l < r && num[l-1] == num[l]);
                    
                }
                
                do {j++;}while(j < num.size() && num[j-1] == num[j]);
            }
            
            do {i++;}while(i < num.size() && num[i-1] == num[i]);
        }
        
        return result;
    }
    
};

int main()
{
    Solution s;
    int a[] = {-1,0,1,2,-1,-4};
    vector<int> v(a, a+6);
    cout << s.fourSum(v, -1).size();
    
    return 0;
}