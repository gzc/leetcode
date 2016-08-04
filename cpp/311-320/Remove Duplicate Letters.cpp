class Solution {
public:
    string removeDuplicateLetters(string s) {
        bool visited[26] = {false};
        int count[26] = {0};
        stack<char> temp_answers;
        for (char ch : s) {
            count[ch - 'a']++;
        }
        
        for (auto ch : s) {
            int index = ch - 'a';
            count[index]--;

            if (visited[index]) continue;
            
            while (!temp_answers.empty() && temp_answers.top() > ch && count[temp_answers.top() - 'a'] > 0) {
                char c = temp_answers.top();
                temp_answers.pop();
                visited[c - 'a'] = false;
            }
            
            if (visited[index] == false) {
                temp_answers.push(ch);
                visited[index] = true;
            }
            
        }
        
        string res("");
        while (!temp_answers.empty()) {
            res = temp_answers.top() + res;
            temp_answers.pop();
        }
        return res;
    }
};
