class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char, int> kmap;
        for (int i = 0; i < keyboard.size(); i++) {
            kmap[keyboard[i]] = i;
        }
        
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            res += abs(kmap[word[i]] - (i == 0 ? 0 : kmap[word[i-1]]));
        }
        return res;
    }
};
