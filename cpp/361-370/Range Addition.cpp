class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        //unordered_map<int, int> mymap;
        
        int mymap[150000] = {0};
        
        for(const vector<int> &vec : updates) {
            mymap[vec[0]] += vec[2];
            mymap[vec[1]+1] -= vec[2];
        }
        
        vector<int> myvec(length, 0);
        
        int v(0);
        
        for(int i = 0;i < length;i++) {
            v = v + mymap[i];
            myvec[i] = v;
        }
        
        return myvec;
        
    }
};
