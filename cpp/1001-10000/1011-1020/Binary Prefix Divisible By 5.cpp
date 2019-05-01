class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> answer(A.size());
        int v = 0;
        
        int i = 0;
        for (int e : A) {
            v = 2*v + e;
            v %= 5;
            answer[i] = v == 0;
            i++;
        }
        
        return answer;
    }
};
