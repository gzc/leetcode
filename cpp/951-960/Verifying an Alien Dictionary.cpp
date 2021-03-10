class Solution {
    
    bool check(const string& previous_word, const string& current_word, char* orders) {
        int len = min(previous_word.length(), current_word.length());
        for (int i = 0; i < len; i++) {
            char p_ch = previous_word[i];
            char c_ch = current_word[i];
            if (orders[p_ch - 'a'] < orders[c_ch - 'a']) return true;
            if (orders[p_ch - 'a'] > orders[c_ch - 'a']) return false;
        }
        return previous_word <= current_word;
    }
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char orders[26];
        for (int i = 0; i < order.length(); i++) {
            orders[order[i] - 'a'] = i;
        }
        
        for (int i = 1; i < words.size(); i++) {
            const string& previous_word = words[i - 1];
            const string& current_word = words[i];
            if (!check(previous_word, current_word, orders)) {
                return false;
            }
        }
        
        return true;
    }
};
