class ValidWordAbbr {
    
    map<string, string> m;
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i = 0;i < dictionary.size();i++) {
            string abbr = dictionary[i].front() + to_string(dictionary[i].length()-2) + dictionary[i].back();
            if(m.count(abbr) > 0 && m[abbr] != dictionary[i]) m[abbr] = "0";
            else m[abbr] = dictionary[i];
        }
    }
    
    bool isUnique(string word) {
        string abbr = word.front() + to_string(word.length()-2) + word.back();
        if(m.count(abbr) > 0 && m[abbr] == "0") return false;
        if(m.count(abbr) > 0 && m[abbr] != word) return false;
        return true;
    }
};