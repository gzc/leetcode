class Solution {
public:
    string smallestSubsequence(string text) {
        
        bool visited[26] = {false};
        int count[26] = {0};
        stack<char> temp_answers;
        for (char ch : text) {
            count[ch - 'a']++;
        }
        
        // bcabc, b -> bc -> a -> ab -> abc
        // cbacdcbc, c -> b -> a -> ac -> acd -> acd -> acdb 
        for (char ch : text) {
            int index = ch - 'a';
            count[index]--;

            if (visited[index]) continue;
            
            while (!temp_answers.empty() && temp_answers.top() > ch && count[temp_answers.top() - 'a'] > 0) {
                char c = temp_answers.top();
                temp_answers.pop();
                visited[c - 'a'] = false;
            }
            
            temp_answers.push(ch);
            visited[index] = true;
        }
        
        string res("");
        while (!temp_answers.empty()) {
            res = temp_answers.top() + res;
            temp_answers.pop();
        }
        return res;
    }
};
