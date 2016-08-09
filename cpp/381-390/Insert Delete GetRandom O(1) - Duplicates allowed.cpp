class RandomizedCollection {
    unordered_map<int, set<int>> value_index_map;
    vector<int> values;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (value_index_map.count(val) == 0) {
            set<int> tmp;
            value_index_map[val] = tmp;
        }
        value_index_map[val].insert(values.size());
        values.push_back(val);
        return value_index_map[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (value_index_map.count(val) == 0 || value_index_map[val].empty()) {
            return false;
        }
        int index = *value_index_map[val].begin();
        value_index_map[values.back()].insert(index);
        value_index_map[values.back()].erase(values.size()-1);
        value_index_map[val].erase(index);
        swap(values[index], values.back());
        values.erase(values.end() - 1);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
