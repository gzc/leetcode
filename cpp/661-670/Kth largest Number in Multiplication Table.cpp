class Solution {
    bool validate(int p, int m, int n, int k){
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (m * (i + 1) <= p) cnt += m;
            else cnt += p / (i+1);
        }
        return cnt >= k;
    }
    
public:
    int findKthNumber(int m, int n, int k) {
        int left = 0;
        int right = n * m +1;
        while(right - left > 1){
            int mid = (left + right) >> 1;
            if(validate(mid, m, n, k)) {
                right = mid;
            }
            else left = mid;
        }
        return right;
    }
};
