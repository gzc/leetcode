vector<string> split(const string &s, char delim) {
    vector<std::string> elems;
    stringstream ss(s);
    string item;
    std::back_inserter(elems);
    while (getline(ss, item, delim)) {
        if (item.length() > 0) {
            elems.push_back(item);
        }
    }
    return elems;
}

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
    string findShortestRoot(const string& word) {
        TrieNode *tmp = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(tmp->nodes[index] == nullptr) {
                return word;
            }
            tmp = tmp->nodes[index];
            if (tmp->word == true) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string returnSentence;
        Trie myTrie;
        
        for (const string& str : dict) {
            myTrie.insert(str);
        }
        
        vector<string> words = split(sentence, ' ');
        for (int i = 0; i < words.size(); i++) {
            returnSentence += myTrie.findShortestRoot(words[i]);
            if (i != words.size() - 1) {
                returnSentence += ' ';
            }
        }
        
        return returnSentence;
    }
};
