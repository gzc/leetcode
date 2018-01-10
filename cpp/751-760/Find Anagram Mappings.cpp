class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> mymap;
        for (int i = 0; i < B.size(); i++) {
            mymap[B[i]] = i;
        }
        
        vector<int> result(A.size());
        for (int i = 0; i < A.size(); i++) {
            result[i] = mymap[A[i]];
        }
        return result;
    }
};
