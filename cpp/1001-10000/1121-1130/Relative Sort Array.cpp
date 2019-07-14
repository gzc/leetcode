class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mymap;
        for (int e : arr1) {
            mymap[e]++;
        }
        
        vector<int> ans;
        
        for (int e : arr2) {
            int times = mymap[e];
            for (int i = 0; i < times; i++) {
                ans.push_back(e);
            }
            mymap[e] = 0;
        }
        
        for (auto it : mymap) {
            if (it.second > 0) {
                int times = it.second;
                for (int i = 0; i < times; i++) {
                    ans.push_back(it.first);
                }
            }
        }
        
        return ans;
    }
};
