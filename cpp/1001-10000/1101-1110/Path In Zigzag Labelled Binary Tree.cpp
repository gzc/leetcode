class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int row = 0;
        int tmp = label;
        int start_number = 1;
        while (tmp > 0) {
            row++;
            tmp = tmp >> 1;
            if (tmp > 0) start_number *= 2;
        }
        
        vector<int> ans;
        
        while (label > 0) {
            
            if (label == 1) {
                ans.insert(ans.begin(), label);
                break;
            }
            
            int a1 = start_number/2;
            int a2 = a1*2 - 1;
            int sum = a1+a2;
            
            ans.insert(ans.begin(), label);
            int t = label/2;
            start_number /= 2;
            
            label = sum - t;
        }
        
        return ans;
    }
};
