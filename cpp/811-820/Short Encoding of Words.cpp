struct TrieNode {
    TrieNode *nodes[26];
    // Initialize your data structure here.
    TrieNode() {
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
    }
    
    int getWordLen() {
        return _getWordLen(root, 0);
    }
    
private:
    TrieNode* root;
    
    int _getWordLen(TrieNode* root, int depth) {
        if (!root) return 0;
        int ans = 0;
        for (TrieNode* child : root->nodes) {
            ans += _getWordLen(child, depth+1);
        }
        if (ans == 0) return depth + 1;
        return ans;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        for (string str : words) {
            reverse(str.begin(), str.end());
            trie.insert(str);
        }
        
        return trie.getWordLen();
    }
};
