struct TrieNode {
    TrieNode *nodes[26];
    bool word;
    // Initialize your data structure here.
    TrieNode(): word(false) {
        memset(nodes, 0, sizeof(nodes));
    }
};

class Trie {
    
    void dfs(TrieNode *tmp, unordered_set<string>& words, string prefix) {
        if (tmp->word) {
            words.insert(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (tmp->nodes[i]) {
                char t = 'a' + i;
                dfs(tmp->nodes[i], words, prefix + t);
            }
        }
    }
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(const string& s) {
        TrieNode *tmp = root;
        for(char ch : s) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                tmp->nodes[index] = new TrieNode();
            }
            tmp = tmp->nodes[index];
        }
        tmp->word = true;
    }
    
    // Returns if the word is in the trie.
    unordered_set<string> search(const string& prefix) {
        unordered_set<string> result;
        TrieNode *tmp = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return result;
            }
            tmp = tmp->nodes[index];
        }
        dfs(tmp, result, prefix);
        return result;
    }
    
private:
    TrieNode* root;
};

class WordFilter {
    
    Trie T1, T2;
    unordered_map<string, int> weights;
    
public:
    WordFilter(vector<string> words) {
        int i = 0;
        for (string word: words) {
            weights[word] = i++;
            T1.insert(word);
            reverse(word.begin(), word.end());
            T2.insert(word);
        }
    }
    
    int f(string prefix, string suffix) {
        unordered_set<string> set1 = T1.search(prefix);
        reverse(suffix.begin(), suffix.end());
        unordered_set<string> set2 = T2.search(suffix);
        
        if (set1.empty() || set2.empty()) return -1;
        
        string ans;
        for (string str : set2) {
            reverse(str.begin(), str.end());
            if (set1.count(str) > 0) {
                if (ans.empty()) {
                    ans = str;
                } else if (weights[ans] < weights[str]) {
                    ans = str;
                }
            }
        }
        
        if (ans.empty()) return -1;
        return weights[ans];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
