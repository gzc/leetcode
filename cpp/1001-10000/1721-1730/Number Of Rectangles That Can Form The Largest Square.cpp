class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> mymap;
        
        int max_square = 0;
        for (const vector<int>& rec : rectangles) {
            int v = *min_element(rec.begin(), rec.end());
            max_square = max(max_square, v);
            mymap[v]++;
        }
        
        return mymap[max_square];
    }
};
