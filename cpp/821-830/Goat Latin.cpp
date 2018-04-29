class Solution {
public:
    string toGoatLatin(string S) {
        stringstream iss(S), oss;
        string vowels("aeiouAEIOU"), word, a;
        while (iss >> word) {
            a.push_back('a');
            if (vowels.find(word[0]) != string::npos) // begin with a vowel
                oss << word;
            else // begin with a consonant
                oss << word.substr(1) << word[0];
            oss << "ma" << a << ' ';
        }
        string res = oss.str();
        res.pop_back();
        return res;
    }
};
