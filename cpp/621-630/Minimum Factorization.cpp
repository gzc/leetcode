class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        string result = "";
        int temp = 9;
        while (temp > 1) {
            if (a % temp == 0) {
                result = to_string(temp) + result;
                a /= temp;
            } else {
                temp--;
            }
        }
        if (a > 10) return 0;
        if (result.length() > 10) return 0;
        if (result.length() < 10) return stoi(result);
        string mm = to_string(INT_MAX);
        if (result > mm) return 0;
        return stoi(result);
    }
};
