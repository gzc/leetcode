class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        vector<int> B;
        while (K > 0) {
            int v = K % 10;
            B.push_back(v);
            K = K / 10;
        }
        
        int carry = 0;
        B.resize(max(A.size(), B.size()));
        for (int i = 0; i < max(A.size(), B.size()); i++) {
            int a = i < A.size() ? A[i] : 0;
            int b = i < B.size() ? B[i] : 0;
            int v = a + b + carry;
            B[i] = v % 10;
            carry = v / 10;
        }
        if (carry) {
            B.push_back(1);
        }
        reverse(B.begin(), B.end());
        return B;
    }
};
