class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int i1 = a.length() - 1;
        int i2 = b.length() - 1;
        while (i1 >= 0 || i2 >= 0 || carry > 0) {
            int v1 = i1 >= 0 ? a[i1] - '0' : 0;
            int v2 = i2 >= 0 ? b[i2] - '0' : 0;
            int sum = v1 + v2 + carry;
            result.push_back((sum & 1) + '0');
            carry = (sum >> 1) & 1;
            i1--;
            i2--;
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};
