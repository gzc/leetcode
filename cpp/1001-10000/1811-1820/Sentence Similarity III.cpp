class Solution {
public:
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            if (item.length() > 0) {
                elems.push_back(item);
            }
        }
        return elems;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');
        int i1 = 0, i2 = 0;
        int j1 = words1.size() - 1, j2 = words2.size() - 1;
        while (i1 <= j1 && i2 <= j2) {
            if (words1[i1] == words2[i2]) {
                i1++;
                i2++;
            } else if (words1[j1] == words2[j2]) {
                j1--;
                j2--;
            } else {
                return false;
            }
        }
        return true;
    }
};
