class Solution {
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        
        for (int i = 0; i < words.size(); i++)
            word_idx[words[i]] = i;
        
        for (int i = 0; i < words.size(); i++) {
            const string& word = words[i];
        
            if (!word.empty() && word_idx.count("") > 0 && isPalindrome(word)) {
                int bidx = word_idx[""];
                res.push_back({i, bidx});
                res.push_back({bidx, i});
            }

            string rword = string(word.rbegin(), word.rend());
            
            if (word_idx.count(rword) > 0) {
                int ridx = word_idx[rword];
                if (i != ridx) {
                    res.push_back({i, ridx});
                }
            }

            for (int j = 1; j < word.length(); j++) {
                string left = word.substr(0, j);
                string rleft = string(left.rbegin(), left.rend());
                string right = word.substr(j);
                string rright = string(right.rbegin(), right.rend());
                if (isPalindrome(left) && word_idx.count(rright) > 0) {
                    res.push_back({word_idx[rright], i});
                }
                if (isPalindrome(right) && word_idx.count(rleft) > 0) {
                    res.push_back({i, word_idx[rleft]});
                }
                
            }
        }
        
        return res;
    }
};


/*
 * Trie Solution
*/
class Trie {
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
    
    struct TrieNode {
        TrieNode *nodes[26];
        bool isWord;
        vector<int> indices;
        int ind;
        TrieNode(): isWord(false) {
            memset(nodes, 0, sizeof(nodes));
        }
    };
    
    TrieNode* root_;
public:
    Trie() {
        root_ = new TrieNode();
    }
    
    void insert(string& s, int wordIndex) {
        TrieNode* tmp = root_;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int ind = s[i]-'a';
            if (tmp->nodes[ind] == nullptr) {
                tmp->nodes[ind] = new TrieNode();
            }
            if (isPalindrome(s.substr(i))) {
                tmp->indices.push_back(wordIndex);
            }
            tmp = tmp->nodes[ind];
        }
        tmp->indices.push_back(wordIndex);
        tmp->ind = wordIndex;
        tmp->isWord = true;
    }
    
    void findPalindrome(const vector<string>& words, int wordIndex, vector<vector<int>>& res) {
        TrieNode* root = root_;
        int m = words[wordIndex].size();
        bool consume_whole_word = true;
        for (int j = 0; j < m; j++) {
            int ind = words[wordIndex][j] - 'a';
            if (root->isWord && isPalindrome(words[wordIndex].substr(j))) {
                if (root->ind != wordIndex) {
                    res.push_back({wordIndex, root->ind});
                }
            }
            root = root->nodes[ind];
            if (root == nullptr) {
                consume_whole_word = false;
                break;
            }
        }
        if (consume_whole_word) {
            for (int index : root->indices) {
                if (index != wordIndex) {
                    res.push_back({wordIndex, index});
                }
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> res;
        Trie trie;
        for (int i = 0; i < n; i++) {
            string current = words[i];
            reverse(current.begin(), current.end());
            trie.insert(current, i);
        }
       
        for (int i = 0; i < n; i++) {
            trie.findPalindrome(words, i, res);
        }
        
        return res;
    }
};
