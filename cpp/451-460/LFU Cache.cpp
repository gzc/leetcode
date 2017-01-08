class LFUCache {
    
    int capacity;
    int size;
    int minFreq;
    
    unordered_map<int, pair<int, int>> m; //key to {value,freq};
    unordered_map<int, list<int>::iterator> mIter; //key to list iterator;
    unordered_map<int, list<int>>  fm;  //freq to key list;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        
        fm[m[key].second].erase(mIter[key]);
        m[key].second++;
        fm[m[key].second].push_back(key);
        mIter[key] = --fm[m[key].second].end();
        
        if (fm[minFreq].empty())
            minFreq++;
        
        return m[key].first;
    }
    
   void put(int key, int value) {
        if (capacity <= 0) return;
        int oldValue = get(key);
        
        // only update the value
        if(oldValue != -1) {
            m[key].first=value;
            return;
        }
        
        // evict the least frequent item
        if (size >= capacity ) {
            int badKey = fm[minFreq].front();
            m.erase(badKey);
            mIter.erase(badKey);
            fm[minFreq].pop_front();
            size--;
        }
        
        m[key] = {value, 1};
        fm[1].push_back(key);
        mIter[key] = --fm[1].end();
        minFreq = 1;
        size++;
    }
};
