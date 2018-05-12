class Solution {
struct TrieNode {
    TrieNode* childs[26];
    TrieNode () {
        memset(childs, 0, sizeof(childs));
    }
};
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size();
        vector<string> dic;
        // select word with the same length as target
        for (const string& s:dictionary) {
            if (s.size() == n) dic.emplace_back(s);
        }
        // build a trie; the depth of all leaves is the same
        TrieNode* root = build(dic);
        // generate abbreviation of target with length 1 until n-1; If it is valid, return
        // For example, if the target is "apple", abbreviation has format of "11p11", whose length is 3
        // This is to help function valid;
        for (int i = 1; i <= n-1; i++) {
            vector<string> abbrs;
            generate_abb(abbrs, target, "", 0, i);
            for (const string& s: abbrs) {
                // encode(s) reformat "11p11" to "2p2"
                if (valid(root, s, 0)) 
                    return encode(s);
            }
        }
        return target;
    }
private:
    void generate_abb(vector<string>& abbrs, string& s, string cur, int pos, int len) {
        // backtracking, ending cases are len = 0 or len = 1;
        if (pos == s.size()) {
            if (len == 0) abbrs.push_back(cur);
            return;
        }
        else if (len == 0)
            return;
        if (len == 1) {
            if (pos != s.size()) {
                for (int i = pos; i < s.size(); i++)
                    cur += '1';
                abbrs.push_back(cur);
            }
            return;
        }
        //next char can be at any index [pos s.size()]
        // if next char at pos, len = len-1;
        // else len = len-2 because we add both a number and a char
        generate_abb(abbrs, s, cur+s[pos], pos+1, len-1);
        for (int i = pos+1; i < s.size(); i++) {
            cur += '1';
            generate_abb(abbrs, s, cur+s[i],  i+1, len-2);
        }
    }
    TrieNode* build(vector<string>& dic) {
        TrieNode* root = new TrieNode();
        for (string s:dic) {
            TrieNode* p = root;
            for (int i = 0; i < s.size(); i++) {
                if (p->childs[s[i]-'a'] == nullptr)
                    p->childs[s[i]-'a'] = new TrieNode();
                p = p->childs[s[i]-'a'];
            }
        }
        return root;
    }
    // if search continues to leaves, there is an conflict, return false;
    bool valid(TrieNode* root, const string& s, int i) {
        if (i == s.size()) return false;
        if (s[i] == '1') {
            for (int j = 0; j < 26; j++) {
                // if any path results in conflict, return false
                if (root->childs[j] && !valid(root->childs[j], s, i+1))
                    return false;
            }
            return true;
        }
        else {
            if (root->childs[s[i]-'a'] == nullptr) 
                return true;;
            return valid(root->childs[s[i]-'a'], s, i+1);
        }
    }
    string encode(const string& s) {
        string ans;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;
            else if (cnt == 0)
                ans += s[i];
            else {
                ans += to_string(cnt)+s[i];
                cnt = 0;
            }
        }
        if (cnt) ans += to_string(cnt);
        return ans;
    }
};
