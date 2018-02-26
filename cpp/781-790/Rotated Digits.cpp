class Solution {
    
    bool isValid(int N) {
        bool validFound = false;
        while (N > 0) {
            int lastDigit = N % 10;
            if (lastDigit == 2 || lastDigit == 5 || lastDigit == 6 || lastDigit == 9) validFound = true;
            if (lastDigit == 3 || lastDigit == 4 || lastDigit == 7) return false;
            N = N / 10;
        }
        return validFound;
    }
    
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i ++) {
            if (isValid(i)) count++;
        }
        return count;
    }
};
