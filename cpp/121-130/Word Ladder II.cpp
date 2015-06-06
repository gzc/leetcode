class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string>> traces;
        unordered_map<string, int> dis;
        queue<string> q;
        dis[start] = 1;
        q.push(start);
        while (!q.empty()) {
            string word = q.front(); q.pop();
            if (word == end) break;
            for (int i = 0; i < word.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string newWord = word;
                    newWord[i] = 'a' + j;
                    if (dict.count(newWord) > 0) {
                        if( dis.count(newWord) == 0 ) {
                            dis[newWord] = dis[word] + 1;
                            vector<string> tmp;
                            tmp.push_back(word);
                            traces[newWord] = tmp;
                            q.push(newWord);
                        } else if(dis[word] + 1 == dis[newWord]){
                            traces[newWord].push_back(word);
                        }
                    }
                }
            }
        }
        vector<vector<string>>paths;
        vector<string> empty;
        helper(start, end, traces, paths, empty);
        return paths;
    }
    
    void helper(string start, string end, unordered_map<string, vector<string>>& traces, vector<vector<string>>& path, vector<string> onepath)
    {
        onepath.insert(onepath.begin(), end);
        if(start == end)
            path.push_back(onepath);
        else {
            vector<string> node = traces[end];
            for(int i = 0;i < node.size();i++)
            {
                string end = node[i];
                helper(start, end, traces, path, onepath);
            }
        }
        
    }
};
