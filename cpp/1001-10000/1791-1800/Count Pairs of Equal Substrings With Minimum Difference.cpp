class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        unordered_map<char, int> last_occurence;
        for (int i = 0; i < secondString.length(); i++) {
            last_occurence[secondString[i]] = i;
        }
        
        int minimum_j_minus_a = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < firstString.length(); i++) {
            char ch = firstString[i];
            if (last_occurence.count(ch) > 0) {
                int j_minus_a = i - last_occurence[ch];
                if (j_minus_a < minimum_j_minus_a) {
                    minimum_j_minus_a = j_minus_a;
                    cnt = 1;
                } else if (j_minus_a == minimum_j_minus_a) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
