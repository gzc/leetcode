#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        if(num[len-1] > num[len-2]) {
            swap(num[len-1], num[len-2]);
            return;
        }
        
        int index1(len), index2(0);
        while(index1 > 1 && num[index1-1] <= num[index1-2])
            index1--;
        if(index1 == 1){
            sort(num.begin(), num.end());
            return;
        }
        int v = num[index1-2];
        sort(num.begin()+index1-1, num.end());
        
        for(int k = index1-1;k < len;k++)
            if(num[k] > v) {
                swap(num[index1-2], num[k]);
                break;
            }
        
        return;
        
    }
    
};

int main()
{
    Solution s;

    int a[] = {1,2};
    vector<int> v(a,a+2);
    s.nextPermutation(v);
    
    for(int i = 0;i < v.size();i++)
        cout << v[i] << endl;
    return 0;
}