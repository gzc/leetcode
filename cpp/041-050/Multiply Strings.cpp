class Solution {
    
public:
    string multiply(string num1, string num2) {
        
        string result(num1.length()+num2.length(), '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0;i < num1.length();i++) {
            int carry = 0;
            int j = 0;
            while (j < num2.size() || carry > 0) {
                int digit = result[i+j] - '0';
                int v = j < num2.size() ? num2[j] : '0';
                int num = (num1[i] - '0') * (v - '0');
                int res = digit + num + carry;
                result[i+j] = (res % 10) + '0';
                carry = res / 10;

                j++;
            }
        }
        
        reverse(result.begin(), result.end());
        while(result[0] == '0' && result.length() > 1)
            result = result.substr(1);
        return result;
    }
    
};
