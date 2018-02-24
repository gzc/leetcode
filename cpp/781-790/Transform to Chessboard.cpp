class Solution {
    
    unsigned int countSetBits(unsigned int n) {
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        map<int, int> mymap;
        for (const vector<int>& row : board) {
            int num = 0;
            for (int e : row) {
                num = 2*num + e;
            }
            mymap[num]++;
        }
        
        int c1 = check(mymap, n);
        if (c1 < 0) return -1;
        
        map<int, int> mymap2;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                num = 2*num + board[j][i];
            }
            mymap2[num]++;
        }
        
        int c2 = check(mymap2, n);
        if (c2 < 0) return -1;
        
        return c1 + c2;
    }
    
    int check(map<int, int>& mymap, int n) {
        if (mymap.size() != 2) return -1;
        int nOne = (1 << n) - 1;
        int key1 = -1, key2 = -1;
        
        // get the two key
        for (auto it : mymap) {
            if (key1 == -1) {
                key1 = it.first;
            } else {
                key2 = it.first;
            }
        }
        
        if ((key1 ^ key2) != nOne) return -1;
        if (abs(mymap[key1] - mymap[key2]) > 1) return -1;
        
        if (n%2 == 1) {
            int totalOne = countSetBits(key1);
            if (totalOne == n / 2) return countSetBits(key1 ^ (0xAAAAAAAA&nOne))/2;
            else return countSetBits(key1 ^ (0x55555555&nOne))/2;
        }
        return (min(countSetBits(key1 ^ (0xAAAAAAAA&nOne)), countSetBits(key1 ^ (0x55555555&nOne))) + 1)/2;
    }
};
