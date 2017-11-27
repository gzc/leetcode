struct TrieNode {
    TrieNode *nodes[26];
    bool word;
    int value;
    // Initialize your data structure here.
    TrieNode(): word(false) {
        memset(nodes, 0, sizeof(nodes));
    }
};

class Trie {
    
    int dfs(TrieNode *tmp) {
        if (tmp == nullptr) return 0;
        int v = 0;
        if (tmp->word) v += tmp->value;
        for (int i = 0; i < 26; i++) v += dfs(tmp->nodes[i]);
        return v;
    }
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(const string& s, int val) {
        TrieNode *tmp = root;
        for(char ch : s) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                tmp->nodes[index] = new TrieNode();
            }
            tmp = tmp->nodes[index];
        }
        tmp->word = true;
        tmp->value = val;
    }
    
    int startsWith(const string& prefix) {
        TrieNode *tmp = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return 0;
            }
            tmp = tmp->nodes[index];
        }
        return dfs(tmp);
    }
    
private:
    TrieNode* root;
};

class MapSum {
    Trie trie;
public:
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        trie.insert(key, val);
    }
    
    int sum(string prefix) {
        return trie.startsWith(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
