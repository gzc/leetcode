/*
                    0  1   2 3 0      1    2 3 0      1    2 3 0  
S1 --------------> abacb | abacb | abacb | abacb | abacb | abacb 
repeatCount ----->    0  |   1   |   1   |   2   |   2   |   3
Increment of 
repeatCount     ->    0  |   1   |   0   |   1   |   0   |   1
nextIndex ------->    2  |   1   |   2   |   1   |   2   |   1


"nlhqgllunmelayl"
10000
"lnl"
10

1       2
10000     20000

0   1     2

1   3     5

1   1     1


"niconiconi"
99981
"nico"
81

0   1   2   3

2   4 

2   2



"nlhqgllunmelayl"
2
"lnl"
1

0     1

1     3

1


*/

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        map<int, int> mymap1, mymap2; // mymap1 : index -> count, mymap2 : nextindex -> s1_pattern_count
        
        int index = 0;
        int repeatCount = 0;
        
        for (int i = 1; i <= n1; i++) {
            
            for (int j = 0; j < s1.size(); j++) {
                
                if (s1[j] == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        repeatCount++;
                        index = 0;
                    }
                }
            }
            
            mymap1[i] = repeatCount;
            
            if (mymap2.count(index) > 0) {
                int start = mymap2[index];
                int cycle = i - start;
                int diff = repeatCount - mymap1[start];
                int pattern_repeat = diff * ( (n1 - start) / cycle);
                int remain = mymap1[start + (n1 - start) % cycle];
                return (pattern_repeat + remain) / n2;
            }
            mymap2[index] = i;
        }
        
        return mymap1[n1-1]/n2;
    }
};

// mymap2[index]
