class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            unordered_map<string, int> dis; // store the distance from start to the current word
            queue<string> q; // FIFO for bfs purpose
            dis[start] = 1;
            q.push(start);
            while (!q.empty()) {
                string word = q.front(); q.pop();
                if (word == end) break;
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
            if (dis.count(end) == 0) return 0;
            return dis[end];
        }
        
};
