class FileSystem {
    map<string, int> mymap;
public:
    FileSystem() {
        mymap[""] = 0;
    }
    
    bool create(string path, int value) {
        size_t pos = path.find_last_of('//');
        if (pos == string::npos) {
            return false;
        }
        
        string parent = path.substr(0, pos);
        if (mymap.count(parent) == 0) return false;
        mymap[path] = value;
        return true;
    }
    
    int get(string path) {
        if (mymap.count(path) == 0) return -1;
        return mymap[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */
