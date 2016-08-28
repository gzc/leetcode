class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry(1);
        for (int i = digits.size()-1; i >= 0; i--) {
            int tmp = digits[i] + carry;
            carry = tmp/10;
            digits[i] = tmp%10;
        }
        
        if (carry)
            digits.emplace(digits.begin(), 1);
        
        return digits;
    }
};
