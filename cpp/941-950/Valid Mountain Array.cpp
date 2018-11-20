class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        if (A[1] <= A[0]) return false;
        if (A[A.size()-2] <= A[A.size()-1]) return false;
        int i = 0, j = A.size()-1;
        while (A[i] < A[i+1]) i++;
        while (A[j] < A[j-1]) j--;
        return i == j;
    }
};
