class TrieNode {
    
public:
    TrieNode *nodes[26];
    bool word;
    // Initialize your data structure here.
    TrieNode() {
        word = false;
        for(int i = 0;i < 26;i++)
            nodes[i]=NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *tmp = root;
        for(int i = 0;i < s.length();i++)
        {
            int index = s[i] - 'a';
            if(tmp->nodes[index] == NULL)
                tmp->nodes[index] = new TrieNode();
            tmp = tmp->nodes[index];
        }
        tmp->word = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *tmp = root;
        for(int i = 0;i < key.length();i++)
        {
            int index = key[i] - 'a';
            if(root->nodes[index] == NULL)
                return false;
            tmp = tmp->nodes[index];
        }
        return tmp->word;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for(int i = 0;i < prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            if(tmp->nodes[index] == NULL)
                return false;
            tmp = tmp->nodes[index];
        }
        return true;
    }
    
private:
    TrieNode* root;
};
