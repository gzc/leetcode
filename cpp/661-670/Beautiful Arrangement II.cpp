class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n, 1);
        bool flag = false;
        int i = 2;
        for (; i <= k; i++) {
            flag = !flag;
            if (flag == false) {
                result[i-1] = result[i-3]+1;
            } else {
                result[i-1] = i-3 >= 0 ? result[i-3]-1 : n;
            }
        }
        if (flag == false) {
            while (i-1 < n && result[i-1] == 1) {
                result[i-1] = result[i-2]+1;
                i++;
            }
        } else {
            while (i-1 < n && result[i-1] == 1) {
                result[i-1] = result[i-2]-1;
                i++;
            }
        }
        return result;
    }
};
