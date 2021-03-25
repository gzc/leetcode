class Trie {
    
    struct TrieNode {
        TrieNode* nodes[26];
        bool word;
        int word_cnt;
        int prefix_cnt;
        // Initialize your data structure here.
        TrieNode(): word(false) {
            memset(nodes, 0, sizeof(nodes));
            word_cnt = 0;
            prefix_cnt = 0;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                tmp->nodes[index] = new TrieNode();
            }
            tmp = tmp->nodes[index];
            tmp->prefix_cnt++;
        }
        tmp->word = true;
        tmp->word_cnt++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* tmp = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return false;
            }
            tmp = tmp->nodes[index];
        }
        return tmp->word_cnt;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* tmp = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(tmp->nodes[index] == nullptr) {
                return 0;
            }
            tmp = tmp->nodes[index];
        }
        return tmp->prefix_cnt;
    }
    
    void erase(string word) {
        TrieNode* tmp = root;
        TrieNode* to_be_deleted = nullptr;
        bool disconnected = false;
        for(char ch : word) {
            int index = ch - 'a';
            TrieNode* parent = tmp;
            tmp = tmp->nodes[index];
            tmp->prefix_cnt--;
            
            if (to_be_deleted != nullptr) {
                delete to_be_deleted;
            }
            if (tmp->prefix_cnt == 0) {
                to_be_deleted = tmp;
                if (disconnected == false) {
                    parent->nodes[index] = nullptr;
                    disconnected = true;
                }
            }
        }
        tmp->word_cnt--;
        if (to_be_deleted != nullptr) {
            delete to_be_deleted;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
