class Solution {
    
    int help(int a, int b) {
        int res(1);
        a %= 1337;
        for (int i = 0; i < b; i++) {
            res = (res * a) % 1337;
        }
        return res;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return help(superPow(a, b), 10) * help(a, last_digit) % 1337;
    }
};
