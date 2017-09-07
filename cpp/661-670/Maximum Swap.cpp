class Solution {
public:
    int maximumSwap(int num) {
        vector<int> records(10, -1);
        string numStr = to_string(num);
        for (int i = 0; i < numStr.size(); i++) {
            records[numStr[i] - '0'] = i;
        }
        
        for (int i = 0; i < numStr.size(); i++) {
            for (int j = 9; j >= 0; j--) {
                if (records[j] > i && j > (numStr[i] - '0')) {
                    swap(numStr[i], numStr[records[j]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};
