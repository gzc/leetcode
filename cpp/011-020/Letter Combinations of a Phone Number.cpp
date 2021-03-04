class Solution {
    
public:
    vector<string> letterCombinations(string digits) {
        string symbols[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        result.push_back("");
        
        for (char ch : digits) {
            int num = ch - '0';
            vector<string> new_result;
            for (const string& s : result) {
                for (char symbol : symbols[num]) {
                    string tmp = s + symbol;
                    new_result.push_back(tmp);
                }
            }
            result.swap(new_result);
        }
        
        return result;
    }
    
};
