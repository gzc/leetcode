class Solution {
public:
    int secondHighest(string s) {
        set<char> nums;
        for (char ch : s) {
            if (isdigit(ch)) {
                nums.insert(ch);
            }
        }
        
        if (nums.size() < 2) {
            return -1;
        }
        return *(++nums.rbegin()) - '0';
    }
};
