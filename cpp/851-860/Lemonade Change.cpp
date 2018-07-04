class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mymap;
        
        for (int e : bills) {
            if (e == 5) {
                mymap[5]++;
            } else if (e == 10) {
                mymap[10]++;
                if (mymap[5] == 0) return false;
                mymap[5]--;
            } else {
                mymap[20]++;
                int remain = 15;
                if (mymap[10] > 0) {
                    remain = 5;
                    mymap[10]--;
                }
                
                while (remain > 0) {
                    if (mymap[5] > 0) {
                        mymap[5]--;
                        remain -= 5;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};
