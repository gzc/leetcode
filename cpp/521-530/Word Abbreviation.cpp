class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> abbres;
        vector<int> lens(n, 1);
        for (const string& word : dict) {
            abbres.push_back(abbreviate(word, 1));
        }
        
        for (int i = 0; i < n; i++) {
            bool unique = false;
            while (!unique) {
                string abbre = abbres[i];
                unique = true;
                for(int j = i + 1; j < n; j++) {
                    if(abbre == abbres[j]) {
                        abbres[j] = abbreviate(dict[j], lens[j]+1);
                        lens[j]++;
                        unique = false;
                    }
                }
                if(unique == false) {
                    abbres[i] = abbreviate(dict[i], lens[i]+1);
                    lens[i]++;
                }
            }
        }
        return abbres;
    }
    
    string abbreviate(const string& s, int len) {
        int num = s.length() - len - 1;
        if (num <= 1) return s;
        return s.substr(0, len) + to_string(num) + s.back();
    }
};
