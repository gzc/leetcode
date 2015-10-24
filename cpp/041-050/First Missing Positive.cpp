class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        
        if(A.empty()) return 1;
        int i(0);
        
        while(i < A.size()) {
            if(A[i] != i+1 && A[i] > 0 && A[i] <= A.size() && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
                continue;
            }
            i++;
        }
        
        for(int i = 0;i < A.size();i++)
            if(A[i] != i+1)
                return i+1;
        return A.back()+1;
    }
};