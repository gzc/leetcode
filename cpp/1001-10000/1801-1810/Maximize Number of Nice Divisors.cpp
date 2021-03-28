class Solution {
    
    long mod = 1e9+7;
    
public:
    int maxNiceDivisors(int primeFactors) {
        int groups_of_3 = primeFactors/3;
        int groups_of_2 = 0;
        int remain = primeFactors - groups_of_3 * 3;
        if (remain == 1) {
            if (groups_of_3 > 0) {
                groups_of_3--;
                groups_of_2 = 2;
            }
        } else if (remain == 2) {
            groups_of_2 = 1;
        }
        
        long ans = 1;
        
        int num_3_used = 0;
        int limit = sqrt(primeFactors);
        int temp = 1;
        while (groups_of_3 > 0) {
            ans *= 3;
            ans %= mod;
            groups_of_3--;
            num_3_used++;
            if (num_3_used == limit) {
                temp = ans;
                break;
            }
        }
        while (groups_of_3 >= limit) {
            ans *= temp;
            ans %= mod;
            groups_of_3 -= limit;
        }
        while (groups_of_3 > 0) {
            ans *= 3;
            ans %= mod;
            groups_of_3--;
            num_3_used++;
        }
        
        while (groups_of_2 > 0) {
            ans *= 2;
            ans %= mod;
            groups_of_2--;
        }
        
        return ans;
    }
};
