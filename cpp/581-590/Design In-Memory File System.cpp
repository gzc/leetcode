class FileSystem {
private:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode *> children;
        TrieNode() : isFile(false) {}
    };

    TrieNode *root;

    vector<string> getPaths(const string &path) {
        vector<string> elems;
        stringstream ss(path);
        string item;
        while (std::getline(ss, item, '/')) {
            if (!item.empty()) {
                elems.push_back(item);
            }
        }
        return elems;
    }

public:
    FileSystem() {
        root = new TrieNode();
    }
    
    vector<string> ls(string path) {
        vector<string> paths = getPaths(path);
        TrieNode *curr = root;
        for (const string &path : paths)
            curr = curr->children[path];
        
        if (curr->isFile)
            return {paths.back()};
        
        vector<string> ans;
        for (auto &p : curr->children)
            ans.push_back(p.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> paths = getPaths(path);
        TrieNode *curr = root;
        for (const string &path : paths) {
            if (!curr->children.count(path))
                curr->children[path] = new TrieNode();
            curr = curr->children[path];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> paths = getPaths(filePath);
        TrieNode *curr = root;
        for (const string &path : paths) {
            if (!curr->children.count(path))
                curr->children[path] = new TrieNode();
            curr = curr->children[path];
        }
        curr->isFile = true;
        curr->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> paths = getPaths(filePath);
        TrieNode *curr = root;
        for (const string &path : paths)
            curr = curr->children[path];
        return curr->content;
    }
};
