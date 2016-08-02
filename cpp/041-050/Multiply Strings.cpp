class Solution {
    
public:
    string multiply(string num1, string num2) {
        
        string result(num1.length()+num2.length(), '0');
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0;i < num1.length();i++)
        {
            int carry(0);
            for (int j = 0;j < num2.length();j++)
            {
                int digit = result[i+j] - '0';
                int num = (num1[i] - '0') * (num2[j] - '0');
                int res = digit + num + carry;
                result[i+j] = (res % 10) + '0';
                carry = res / 10;
            }
            
            int index = i + num2.size();
            while (carry)
            {
                int digit = result[index] - '0';
                int res = digit + carry;
                result[index] = (res % 10) + '0';
                carry = res / 10;
            }
        }
        
        reverse(result.begin(), result.end());
        while(result[0] == '0' && result.length() > 1)
            result = result.substr(1);
        return result;
    }
    
};
