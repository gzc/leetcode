class Solution {
public:
    struct TrieNode {
        vector<int> indexs;
        vector<TrieNode*> children;
        TrieNode(): children(26, nullptr) { }
    };

    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int j = 0; j < words.size(); j++) {
            TrieNode* t = root;
            for (int i = 0; i < words[j].size(); i++) {
                if (!t->children[words[j][i] - 'a'])
                    t->children[words[j][i] - 'a'] = new TrieNode();
                t = t->children[words[j][i] - 'a'];
                t->indexs.push_back(j);
            }
        }
        return root;
    }
    
    vector<vector<string>> res;
    vector<string> vec;
    void backtrack(const vector<string>& words, int level, TrieNode* root) {
        if (level >= words[0].size()) {
            res.emplace_back(vec);
            return;
        }
        string str;
        for (int i = 0; i < level; i++) 
            str += vec[i][level];
        TrieNode* t = root;     
        for (int i = 0; i < str.size(); i++) 
            if (!(t = t->children[str[i] - 'a'])) return;
        for (int index : t->indexs) {
            vec[level] = words[index];
            backtrack(words, level + 1, root);
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return res;
        TrieNode* root = buildTrie(words);
        vec.resize((int)words[0].size());
        for (const string& word : words) {
            vec[0] = word;
            backtrack(words, 1, root);
        }
        return res;
    }
};
