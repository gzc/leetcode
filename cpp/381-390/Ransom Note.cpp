class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int chs[128] = {0};
        for (char ch : magazine) chs[ch]++;
        for (char ch : ransomNote)
            if (--chs[ch] < 0)
                return false;
        return true;
    }
};
