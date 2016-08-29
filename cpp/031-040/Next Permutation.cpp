class Solution {
    
public:
    void nextPermutation(vector<int> &num) {
        if (num.empty()) return;
        
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i(0);
        for (i = num.size()-2; i >= 0; --i)
            if (num[i] < num[i+1]) break;
        
        // reverse all the numbers after violated number
        reverse(begin(num)+i+1, end(num));
        
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(num.begin()+i+1, num.end(), num[i]);
        
        // swap them, done!
        swap(num[i], *itr);
    }
    
};
