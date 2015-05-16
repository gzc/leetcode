#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <string>

using namespace std;



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
    
    bool _search(string word, int offset, TrieNode *node)
    {
        if(!node) return false;
        
        if(offset == word.length())
        {
            if(node && node->word) return true;
            return false;
        }
        
        if(word[offset] == '.')
        {
            for(int j = 0;j < 26;j++)
            {
                bool fff = _search(word, offset+1, node->nodes[j]);
                if(fff) return true;
            }
            return false;
        } else {
            return _search(word, offset+1, node->nodes[word[offset]-'a']);
        }
    }
    
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
    bool search(string word) {
        return _search(word, 0, root);
    }
    
private:
    TrieNode* root;
};



class WordDictionary {
    
    Trie trie;
    
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie.search(word);
    }
};





int main()
{
    //addWord("a"),addWord("a"),search("."),search("a"),search("aa"),search("a"),search(".a"),search("a.")

    WordDictionary wd;
    wd.addWord("a");
    wd.addWord("a");
    cout << wd.search(".") << endl;
    cout << wd.search("a") << endl;
    cout << wd.search("aa") << endl;
    cout << wd.search("a") << endl;
    cout << wd.search(".a") << endl;
    cout << wd.search("a.") << endl;
    
    cout << "-----end----" << endl;
    
}
