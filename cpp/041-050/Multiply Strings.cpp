#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    
public:
    string multiply(string num1, string num2) {
        
        string s(num1.length()+num2.length(),'0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for(int i = 0;i < num1.length();i++)
        {
            int flag = 0;
            for(int j = 0;j < num2.length();j++)
            {
                int digit = s[i+j] - '0';
                int num = (num1[i] - '0') * (num2[j] - '0');
                int res = digit + num + flag;
                s[i+j] = (res % 10) + '0';
                flag = res / 10;
            }
            
            int index = i + num2.size();
            while(flag)
            {
                int digit = s[index] - '0';
                int res = digit + flag;
                s[index] = (res % 10) + '0';
                flag = res / 10;
            }
        }
        
        
        reverse(s.begin(), s.end());
        while(s[0] == '0' && s.length() > 1)
            s = s.substr(1);
        return s;
    }
    
};

int main()
{
    Solution s;
    cout << s.multiply("999", "777");

    return 0;
}