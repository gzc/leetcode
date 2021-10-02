
   
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(begin(wordList), end(wordList));
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int step = 1;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return step;
                }
                for (int i = 0; i < word.size(); i++) {
                    char ch = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (visited.count(word) == 0 && dict.count(word) > 0) {
                            visited.insert(word);
                            q.push(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            
            step++;
        }
        
        return 0;
    }
};
