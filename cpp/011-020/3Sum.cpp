class Solution {
    
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if (num.size() < 3) return result;
        
        sort(num.begin(), num.end());
        int buf1(INT_MAX), buf2(INT_MAX), buf3(INT_MAX);
        
        for (int i = 0;i < num.size()-2;) {
            int remain = -num[i];
            int j = i+1;
            int k = num.size()-1;
            
            while (j < k && j < num.size()-1) {
                int tmp = num[j] + num[k];
                if (tmp == remain) {
                    int a[3] = {num[i], num[j], num[k]};
                    vector<int> v(a, a+3);
                    if (!(num[i] == buf1 && num[j] == buf2 && num[k] == buf3)) {
                        buf1 = num[i];
                        buf2 = num[j];
                        buf3 = num[k];
                        result.push_back(v);
                    }
                    j++;
                    k--;
                }
                else if (tmp > remain) k--;
                else j++;
            }
            
            do {
                i++;
            }
            while (i < num.size() && num[i-1] == num[i]);
        }
        return result;
    }
    
};
