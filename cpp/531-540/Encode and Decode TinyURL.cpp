class Solution {
    
    int count = 0;
    unordered_map<int, string> mymap;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string short_url = "http://tinyurl.com/" + to_string(count);
        mymap[count] = longUrl;
        count++;
        return short_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string num = shortUrl.substr(19);
        return mymap[stoi(num)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
