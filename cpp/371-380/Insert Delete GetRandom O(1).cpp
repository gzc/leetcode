class RandomizedSet {
    unordered_map<int, int> value_index_map;
    vector<int> values;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (value_index_map.count(val) > 0) {
            return false;
        }
        value_index_map[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (value_index_map.count(val) == 0) {
            return false;
        }
        int index = value_index_map[val];
        value_index_map[values.back()] = index;
        value_index_map.erase(val);
        swap(values[index], values.back());
        values.erase(values.end() - 1);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
