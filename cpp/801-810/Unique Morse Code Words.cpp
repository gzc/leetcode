class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> s;
        for (const auto& word : words) {
            string code;
            for (auto c : word) code += d[c - 'a'];
            s.insert(code);
        }
        return s.size();
    }
};
