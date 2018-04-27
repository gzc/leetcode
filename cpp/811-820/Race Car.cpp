class Solution {
    
    int reverseSpeed(int speed) {
        return speed > 0 ? -1 : 1;
    }
    
public:
    // (pos, speed) determines current state
    int racecar(int target) {
        // {pos, speed}
        unordered_set<string> visited;
        queue<pair<int, int>> myqueue;
        myqueue.push({0, 1});
        visited.insert("0.1");
        int level = 0;
        
        while (!myqueue.empty()) {
            
            int mysize = myqueue.size();
            
            for (int i = 0; i < mysize; i++) {
                pair<int, int> cur = myqueue.front();
                myqueue.pop();
                if (cur.first == target) {
                    return level;
                }

                pair<int, int> first = make_pair(cur.first + cur.second, cur.second*2);
                pair<int, int> second = make_pair(cur.first, reverseSpeed(cur.second));
                string key1 = to_string(first.first) + "." + to_string(first.second);
                string key2 = to_string(second.first) + "." + to_string(second.second);
                
                if (first.first >= 0 && first.first <= 2*target && visited.count(key1) == 0) {
                    visited.insert(key1);
                    myqueue.emplace(first);
                }
                if (second.first >= 0 && second.first <= 2*target && visited.count(key2) == 0) {
                    visited.insert(key2);
                    myqueue.emplace(second);
                }
            }
            level++;
        }
        
        return -1;
    }
};
