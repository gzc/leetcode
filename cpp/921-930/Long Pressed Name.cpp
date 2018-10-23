class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        for (char ch : name) {
            if (typed[i] == ch) { i++; continue; }
            while (i > 0 && i < typed.size() && typed[i] == typed[i-1]) i++;
            if (typed[i] == ch) { i++; continue; }
            else return false;
        }
        return true;
    }
};
