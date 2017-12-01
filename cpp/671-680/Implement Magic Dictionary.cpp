struct TrieNode {
    TrieNode *nodes[26];
    bool word;
    // Initialize your data structure here.
    TrieNode(): word(false) {
        memset(nodes, 0, sizeof(nodes));
    }
};

class Trie {
    
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
    bool search(TrieNode* tmp, const string& key, int strIndex, int count) {
        if (tmp == nullptr) return false;
        if (count > 1) return false;
        if (strIndex == key.length()) {
            return count == 1 && tmp->word;
        }
        char ch = key[strIndex];
        int index = ch - 'a';
        for (int i = 0; i < 26; i++) {
            int added = index == i ? 0 : 1;
            if (search(tmp->nodes[i], key, strIndex+1, count+added)) return true;
        }
        return false;
    }
    
    TrieNode* root;
};

class MagicDictionary {
    Trie trie;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string& word : dict) trie.insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return trie.search(trie.root, word, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
