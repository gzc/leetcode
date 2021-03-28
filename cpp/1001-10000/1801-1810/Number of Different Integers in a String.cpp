class Solution {
public:
    int numDifferentIntegers(string word) {
        word += 'a';
        set<string> s;
        string tmp;
        for (char ch : word) {
            if (isdigit(ch)) {
                tmp += ch;
            } else {
                while (tmp.length() > 1 && tmp[0] == '0') {
                    tmp = tmp.substr(1);
                }
                if (!tmp.empty()) s.insert(tmp);
               tmp = ""; 
            }
        }
        
        return s.size();
    }
};
