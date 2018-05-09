class Solution {
    
    int dfs(const string& ring, const string& key, int index, map<string, int>& mymap){
        if (index == key.length()) {
            return 0;
        }
        string hashKey = ring + to_string(index);
        if (mymap.find(hashKey) != mymap.end()) return mymap[hashKey];
        
        int minSteps = INT_MAX;
        for (int i = 0; i < ring.length(); i ++) {
            if (ring[i] == key[index]){
                string s = ring.substr(i, ring.length()) + ring.substr(0, i);
                int steps = 1 + min(i, (int)ring.length() - i);
                steps += dfs(s, key, index + 1, mymap);
                minSteps = min(minSteps, steps);
            }
        }
        
        return mymap[hashKey] = minSteps;
    }
    
public:
    int findRotateSteps(string ring, string key) {
        map<string, int> mymap;
        return dfs(ring, key, 0, mymap);
    }
};
