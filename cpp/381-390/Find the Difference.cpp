class Solution {
public:
    char findTheDifference(string s, string t) {
        char onemore(0);
        for (char ch : s) onemore ^= ch;
        for (char ch : t) onemore ^= ch;
        return onemore;
    }
};
