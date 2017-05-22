class Solution {
    int dSquare(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
public:
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({ dSquare(p1, p2), dSquare(p1, p3), dSquare(p1, p4),
            dSquare(p2, p3), dSquare(p2, p4), dSquare(p3, p4) });
        return !s.count(0) && s.size() == 2;
    }
    
};
