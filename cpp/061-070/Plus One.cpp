class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        reverse(digits.begin(), digits.end());
        
        int add(1);
        for(int i = 0;i < digits.size();i++)
        {
            int tmp = digits[i] + add;
            add = tmp/10;
            digits[i] = tmp%10;
        }
        
        if(add)
            digits.push_back(1);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
