#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    
    string p[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> v;
        
        if(digits.length() == 0) return v;
        v.push_back("");
        
        for(int i = 0;i < digits.length();i++)
        {
            int num = digits[i]-'0';
            int l = v.size();
            for(int j = 0;j < l;j++)
            {
                string s = v[j];
                string letter = p[num];
                for(int k = 0;k < letter.length();k++)
                {
                    string tmp = s+letter[k];
                    v.push_back(tmp);
                }
            }
            v.erase(v.begin(), v.begin()+l);
        }
        
        
        return v;
    }
    
};

int main()
{
    Solution s;
    vector<string>v = s.letterCombinations("23");
    
    for(int i = 0;i < v.size();i++)
        cout << v[i] << endl;
    
    return 0;
}