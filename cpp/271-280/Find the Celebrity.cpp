// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i(0),j(n-1);
        
        while(i < j)
        {
            if(knows(i, j)) i++;
            else j--;
        }
        
        for(int k = 0;k < n;k++)
        {
            if(k == i) continue;
            if(!knows(k, i)) return -1;
            if(knows(i, k)) return -1;
        }
        return i;
    }
};