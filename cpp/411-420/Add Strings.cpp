class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        int i1 = num1.length() - 1;
        int i2 = num2.length() - 1;
        while (i1 >= 0 || i2 >= 0) {
            int v1 = i1 >= 0 ? num1[i1] - '0' : 0;
            int v2 = i2 >= 0 ? num2[i2] - '0' : 0;
            int sum = v1 + v2 + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
            i1--;
            i2--;
        }
        
        if (carry) {
            result.push_back('1');
        }
        reverse(begin(result), end(result));
        return result;
    }
};
