#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> r;
        for(int i = 0;i < numbers.size();i++) {
            int remain = target - numbers[i];
            if(m.count(remain) > 0) {
                r.push_back(m[remain]);
                r.push_back(i+1);
                return r;
            } else {
                m[numbers[i]] = i+1;
            }
        }
        return r;
    }
};

int main()
{
    int a[3] = {3,2,4};
    vector<int> v{a, a+3};
    Solution s;
    s.twoSum(v, 6);
    
    return 0;
}