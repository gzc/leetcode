class Solution {
    
    string symbols[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        result.emplace(result.end(), "");
        
        for (int i = 0;i < digits.length();i++)
        {
            int num = digits[i]-'0';
            int current_combinations = result.size();
            for (int j = 0;j < current_combinations;j++)
            {
                string s = result[j];
                string letters = symbols[num];
                for (int k = 0;k < letters.length();k++)
                {
                    string tmp = s+letters[k];
                    result.emplace(result.end(), tmp);
                }
            }
            result.erase(result.begin(), result.begin()+current_combinations);
        }
        
        return result;
    }
    
};
