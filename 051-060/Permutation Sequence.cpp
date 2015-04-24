#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int pTable[10] = {1};
        for(int i = 1; i <= 9; i++){
            pTable[i] = i * pTable[i - 1];
        }
        string result;
        char a[] = {'1','2','3','4','5','6','7','8','9'};
        vector<char> numSet(a, a+9);
        while(n > 0){
            int temp = (k - 1) / pTable[n - 1];
            result += numSet[temp];
            numSet.erase(numSet.begin() + temp);
            k = k - temp * pTable[n - 1];
            n--;
        }
        return result;
    }
    
};

int main()
{
    Solution s;
    cout << s.getPermutation(3, 5);
    
    return 0;
}