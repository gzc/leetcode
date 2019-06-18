class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        
        int i = 0, j = 0;
        int add_on = 0;
        
        while (i < arr1.size() || j < arr2.size() || add_on != 0) {
            int a = i < arr1.size() ? arr1[i] : 0;
            int b = j < arr2.size() ? arr2[j] : 0;
            
            int v = a + b + add_on;
            
            if (v == -1) {
                v = 1;
                add_on = 1;
            } else if (v >= 2) {
                v = v%2;
                add_on = -1;
            } else {
                add_on = 0;
            }
            
                
            ans.push_back(v);
            i++; j++;
        }
        
        reverse(ans.begin(), ans.end());
        while (ans.size() > 1 && ans[0] == 0) ans.erase(begin(ans));
        return ans;
    }
};
