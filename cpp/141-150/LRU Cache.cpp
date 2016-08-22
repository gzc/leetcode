class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;
    
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    HIPII cache;
    LI used;
    int _capacity;
};
