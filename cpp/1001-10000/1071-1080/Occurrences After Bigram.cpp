class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string matched_string = first + " " + second;
        vector<string> return_ans;
        int idx = 0;
        
        while ((idx = text.find(matched_string, idx)) >= 0) {
            int start = idx + matched_string.size() + 1;
            if (start >= text.size()) break;
            int end = start;
            while (end < text.size() && text[end] != ' ') {
                end++;
            }
            string third = text.substr(start, end-start);
            return_ans.push_back(third);
            idx = start;
        }
        
        return return_ans;
    }
};
