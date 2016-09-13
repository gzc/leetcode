class Solution {
    
public:
    int maxRotateFunction(vector<int>& A) {
        
        int res(INT_MIN), sum(0), temp(0);
        int n = A.size();
        
        int i(1), j(0);
        
        int times = 1;
        for (int k = 1; k < n; k++) {
            sum += A[k];
            temp += times * A[k];
            times++;
        }
        
        res = temp;
        
        while (j < A.size()) {
            temp -= sum;
            temp += (n-1) * A[j];
            sum = sum - A[i] + A[j];
            i = (++i)%n;
            j++;
            res = max(res, temp);
        }
        
        return res;
    }
};
