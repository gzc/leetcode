struct TrieNode {
    unordered_map<char, TrieNode*> nodes;
    bool word;
    // Initialize your data structure here.
    TrieNode(): word(false) { }
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
            int index = ch;
            if(tmp->nodes[index] == nullptr) {
                tmp->nodes[index] = new TrieNode();
            }
            tmp = tmp->nodes[index];
        }
        tmp->word = true;
    }
    
    int search(const string& s, int i) const {
        TrieNode *tmp = root;
        int maxLen = 0;
        int j = i;
        for(; j < s.length(); j++) {
            int index = s[j];
            if (tmp->word) maxLen = max(maxLen, j - i);
            if(tmp->nodes[index] == nullptr) return maxLen;
            tmp = tmp->nodes[index];
        }
        if (tmp->word) {
            int temp = j - i + 1;
            maxLen = max(maxLen, temp);
        }
        return maxLen;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    string boldWords(vector<string>& dict, string s) {
        vector<bool> myvec(s.length(), false);
        Trie trie;
        for (const string& str : dict) trie.insert(str);
        
        int end = 0;
        for (int i = 0; i < s.length(); i++) {
            int maxLen = trie.search(s, i);
            end = max(end, i + maxLen);
            myvec[i] = end > i;
        }
        
        std::stringstream ss;
        string result = "";
        for (int i = 0; i < myvec.size(); i++) {
            if (!myvec[i]) {
                ss << s[i];
            } else {
                int j = i + 1;
                while (j < myvec.size() && myvec[j]) j++;
                ss << "<b>";
                ss << s.substr(i, j - i);
                ss << "</b>";
                i = j - 1;
            }
        }
        ss >> result;
        return result;
    }
};
