class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        int res = 0;
        for(int i = 0;i < words.size(); i++) {
            for(auto ch : words[i]) mask[i] |= (1 << (ch - 'a'));
            for(int j = 0;j < i;j++) {
                if( (mask[i] & mask[j]) == 0)
                    res = max(res, int(words[i].length() * words[j].length()));
            }
        }
        return res;
    }
};