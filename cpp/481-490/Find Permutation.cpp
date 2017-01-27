class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == 'I' || i == s.size()) {
                int curL = result.size();
                for (int j = i+1; j > curL; j--) {
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
