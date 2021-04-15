class Solution {
    
    unordered_map<string, int> mymap;
    
    bool isPalindrome(string word) {
            int size = word.length();
            for(int i = 0;i < size/2;i++)
                if(word[i] != word[size - i - 1])
                    return false;
            return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> ans;
        
        for(int i = 0;i < words.size();i++)
            mymap[words[i]] = i;
        
        for(int i = 0;i < words.size();i++) {
            const string& word = words[i];
        
            if (mymap.count("") > 0 && word != "" && isPalindrome(word)) {
                int bidx = mymap[""];
                vector<int> v1 = {i, bidx};
                vector<int> v2 = {bidx, i};
                ans.push_back(v1);
                ans.push_back(v2);
            }

            string rword = string(word.rbegin(), word.rend());
            
            if (mymap.count(rword) > 0) {
                int ridx = mymap[rword];
                if (i != ridx) {
                    vector<int> v1 = {i, ridx};
                    ans.push_back(v1);
                }
            }

            for(int j = 1;j < word.length();j++) {
                string left = word.substr(0, j);
                string rleft = string(left.rbegin(), left.rend());
                string right = word.substr(j);
                string rright = string(right.rbegin(), right.rend());
                if(isPalindrome(left) && mymap.count(rright) > 0) {
                    vector<int> v1 = {mymap[rright], i};
                    ans.push_back(v1);
                }
                if(isPalindrome(right) && mymap.count(rleft) > 0) {
                    vector<int> v1 = {i, mymap[rleft]};
                    ans.push_back(v1);
                }
                
            }
        }
        return ans;
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
