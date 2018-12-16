class Solution {
    
    vector<int> int2vec(int n) {
        vector<int> result(8, 0);
        for (int i = 0; i < 8; i++) {
            int v = n & 1;
            result[7 - i] = v;
            n /= 2;
        }
        return result;
    }
    
    int ith(int a, int i) {
        return (a >> i) & 1; 
    }
    
    int transform(int num) {
        int result = 0;
        for (int i = 1; i <= 6; i++) {
            int tmp = (ith(num, i-1) == ith(num, i+1));
            result |= (tmp << i);
        }
        result &= 126;
        return result;
    }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int start = 0;
        for (auto p = cells.begin(); p != cells.end(); p++) {
            start *= 2;
            start |= *p;
        }
        
        map<int, int> mymap;
        map<int, int> step2v;
        mymap[start] = 0;
        step2v[0] = start;
        
        int i = 0;
        while (i < N) {
            start = transform(start);
            i++;
            if (mymap.count(start) == 1) {
                int coef = i - mymap[start];
                int mystep = ((N - i) % coef) + mymap[start];
                return int2vec(step2v[mystep]);
            }
            mymap[start] = i;
            step2v[i] = start;
        }
        
        return int2vec(start);
    }
};
