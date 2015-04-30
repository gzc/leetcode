class Solution {
public:
    void sortColors(int A[], int n) {
        int i, j;
        i = j;
        
        for(int r = 0; r < n; r++)
        {
            if(A[r] == 0)
            {
                swap(A[j],A[r]);
                swap(A[i],A[j]);
                i++;
                j++;
            } else if(A[r] == 1)
            {
                swap(A[r],A[j]);
                j++;
            }
        }
        
    }
};
