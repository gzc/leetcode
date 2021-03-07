class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.empty()) {
            return;
        }
        
        int violation_index = num.size() - 2;
        for (; violation_index >= 0; violation_index--) {
            if (num[violation_index] < num[violation_index+1]) {
                break;
            }
        }
        
        reverse(begin(num) + violation_index + 1, end(num));
        
        if (violation_index == -1) {
            return;
        }
        
        auto it = upper_bound(begin(num) + violation_index + 1, num.end(), num[violation_index]);

        swap(num[violation_index], *it);
    }
    
};
