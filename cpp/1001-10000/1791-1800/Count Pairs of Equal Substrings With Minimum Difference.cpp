class Solution {
public:
    int countQuadruples(string firstString, string secondString) {
        unordered_map<char, int> last_occurence;
        for (int i = 0; i < secondString.length(); i++) {
            last_occurence[secondString[i]] = i;
        }
        
        map<int, int> counts;
        for (int i = 0; i < firstString.length(); i++) {
            char ch = firstString[i];
            if (last_occurence.count(ch) > 0) {
                counts[i - last_occurence[ch]]++;
            }
        }
        
        return counts.empty() ? 0 : counts.begin()->second;
    }
};
