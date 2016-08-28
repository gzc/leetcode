class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result("");
        for (const string& str : strs) {
            string len = to_string(str.length());
            result = result + len + "#" + str;
        }
        return result;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        size_t i = 0;
        while (i < s.length()) {
            size_t index = s.find('#', i);
            int len = stoi(s.substr(i, index-i));
            result.push_back(s.substr(index+1, len));
            i = index + len + 1;
        }
        return result;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
