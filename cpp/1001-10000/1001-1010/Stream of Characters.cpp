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
    
    bool eat(char ch) {
        vector<TrieNode*> tmp;
        if (root->nodes[ch - 'a'] != nullptr) {
            tmp.push_back(root->nodes[ch - 'a']);
        }
        for (TrieNode* node : state) {
            if (node->nodes[ch - 'a'] != nullptr) {
                tmp.push_back(node->nodes[ch - 'a']);
            }
        }
        
        swap(state, tmp);
        bool return_val = false;
        for (TrieNode* node : state) {
            if (node->word) {
                return_val = true;
                break;
            }
        }
        return return_val;
    }

    
private:
    TrieNode* root;
    vector<TrieNode*> state;
};

class StreamChecker {
    Trie trie;
public:
    StreamChecker(vector<string>& words) {
        for (const string& word : words) {
            trie.insert(word);
        }
    }
    
    bool query(char letter) {
        return trie.eat(letter);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
