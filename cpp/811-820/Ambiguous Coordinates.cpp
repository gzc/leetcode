class Solution {
    
    // 1.0 -> false
    // 0001 -> false
    // 0.0
    bool valid(const string& str) {
        string part1(str), part2;
        int idx = str.find('.');
        if (idx >= 0) {
            part1 = str.substr(0, idx);
            part2 = str.substr(idx + 1);
        }
        
        if (part1.length() != to_string(stol(part1)).length()) return false;
        if (part2.length() > 0) {
            if (stol(part2) == 0) return false;
            reverse(part2.begin(), part2.end());
            if (part2.length() != to_string(stol(part2)).length()) return false;
        }
        
        return true;
    }
    
    // Given a string, return all possible results
    // 123 -> [1.23, 12.3, 123]
    vector<string> make(const string& str) {
        vector<string> result;
        for (int i = 1; i < str.length(); i++) {
            string temp(str);
            temp.insert(i, 1, '.');
            if (valid(temp))
                result.push_back(temp);
        }
        if (valid(str)) result.push_back(str);
        return result;
    }
    
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> result;
        int len = S.length();
        for (int i = 1; i < S.length() - 2; i++) {
            string leftStr = S.substr(1, i);
            string rightStr = S.substr(i+1, len - 2 - i);
            
            vector<string> left = make(leftStr);
            vector<string> right = make(rightStr);
            
            for (const string& ls : left) {
                for (const string& rs : right) {
                    string ans = "("  + ls + ", " + rs + ")";
                    result.push_back(ans);
                }
            }
        }
        return result;
    }
};
