class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int numOfOne = 0;
        for (int e : A) numOfOne += e;
        
        if (numOfOne == 0) return { 0, A.size()-1 };
        
        if (numOfOne % 3 != 0) return { -1, -1 };
        
        int expectedOne = numOfOne / 3;
        
        int paddingZero = 0;
        int currentOne = 0;
        int pos = A.size() - 1;
        while (currentOne < expectedOne) {
            if(A[pos] == 1) {
                currentOne++;
            } else {
                if (currentOne == 0) {
                    paddingZero++;
                }
            }
            pos--;
        }
        
        int currentPaddingZero = 0;
        while (A[pos] == 0) {
            currentPaddingZero++;
            pos--;
        }
        if (currentPaddingZero < paddingZero) return { -1, -1 };
        
        int pos2 = pos + 1 + paddingZero;
        
        currentOne = 0;
        while (currentOne < expectedOne) {
            if(A[pos] == 1) {
                currentOne++;
            }
            pos--;
        }
        
        currentPaddingZero = 0;
        while (pos >=0 && A[pos] == 0) {
            currentPaddingZero++;
            pos--;
        }
        if (currentPaddingZero < paddingZero) return { -1, -1 };
        
        int i = pos + paddingZero, j = pos2-1;
        while (i >= 0 && j > pos) {
            if (A[i] != A[j]) return { -1, -1 };
            i--;
            j--;
        }
        
        return { pos + paddingZero, pos2 };
    }
};
