class HitCounter {
    
    map<int, int> mymap;
    int total;
    
public:
    /** Initialize your data structure here. */
    HitCounter() {
        total = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        mymap[timestamp]++;
        total++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        
        while(!mymap.empty()) {
            auto it = mymap.begin();
            if(timestamp - it->first >= 300) {
                total -= it->second;
                mymap.erase(it);
            } else {
                break;
            }
        }
        
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
