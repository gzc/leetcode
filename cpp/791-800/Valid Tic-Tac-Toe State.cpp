class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<int> rowSum(3, 0);
        vector<int> colSum(3, 0);
        int dig1 = 0, dig2 = 0;
        int numX = 0, numO = 0;
        
        int winX = 0, winO = 0;
        
        for (int i = 0; i < 3; i++) {
            string str = board[i];
            for (int j = 0; j < str.length(); j++) {
                if (str[j] == 'X') {
                    numX++;
                    rowSum[i]++;
                    colSum[j]++;
                    if (i == j) dig1++;
                    if (i + j == 2) dig2++;
                } else if (str[j] == 'O') {
                    numO++;
                    rowSum[i]--;
                    colSum[j]--;
                    if (i == j) dig1--;
                    if (i + j == 2) dig2--;
                }
                if (rowSum[i] == 3) winX++;
                if (colSum[j] == 3) winX++;
                if (dig1 == 3) winX++;
                if (dig2 == 3) winX++;
                if (rowSum[i] == -3) winO++;
                if (colSum[j] == -3) winO++;
                if (dig1 == -3) winO++;
                if (dig2 == -3) winO++;
                if (winX > 0 && winO > 0) return false;
            }
        }
        
        if (winX > 0) {
            if (numX != numO + 1) return false;
        } else if (winO > 0) {
            if (numX != numO) return false;
        }
        if (numO > numX || numX - numO >= 2) return false;
        
        return true;
    }
};
