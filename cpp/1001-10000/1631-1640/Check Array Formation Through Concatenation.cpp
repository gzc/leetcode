class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> mymap;
        for (int i = 0; i < arr.size(); i++) {
            mymap[arr[i]] = i;
        }
        
        for (const vector<int>& piece : pieces) {
            for (int i = 0; i < piece.size(); i++) {
                if (mymap.count(piece[i]) == 0) {
                    return false;
                }
            }
        }
        
        for (const vector<int>& piece : pieces) {
            for (int i = 1; i < piece.size(); i++) {
                if (mymap[piece[i-1]] > mymap[piece[i]]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
