class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewel;
        for (char ch : J) jewel.insert(ch);
        int ans = 0;
        for (char ch : S) {
            if (jewel.count(ch) > 0) {
                ans++;
            }
        }
        return ans;
    }
};
