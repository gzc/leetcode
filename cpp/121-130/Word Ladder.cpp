class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(begin(wordList), end(wordList));
        unordered_map<string, int> dis; // store the distance from start to the current word
        queue<string> q; // FIFO for bfs purpose
        dis[beginWord] = 1;
        q.push(beginWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            if (word == endWord) break;
            for (int i = 0; i < word.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string newWord = word;
                    newWord[i] = 'a' + j;
                    if (dict.count(newWord) > 0 && dis.count(newWord) == 0) {
                        dis[newWord] = dis[word] + 1;
                        q.push(newWord);
                    }
                }
            }
        }
        if (dis.count(endWord) == 0) return 0;
        return dis[endWord];
    }
};
