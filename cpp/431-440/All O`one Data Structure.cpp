class AllOne {
public:

    void inc(string key) {
        
        // If the key doesn't exist, insert it with value 0.
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
            
        // Insert the key in next bucket and update the lookup.
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end() || next->value > bucket->value + 1)
            next = buckets.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!bucketOfKey.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        list<Bucket>::iterator prev = bucketOfKey[key], bucket = buckets.begin();
        if (prev != buckets.begin()) bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};
