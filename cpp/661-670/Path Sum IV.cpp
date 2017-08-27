class Solution {
    int getLeftChild(int key) {
        int d = key/10;
        int p = key%10;
        return 10*(d+1) + (2*p-1);
    }
public:
    int pathSum(vector<int>& nums) {
        map<int, int> mymap;
        for (int num : nums) {
            int key = num/10;
            int value = num%10;
            mymap[key] = value;
        }
        
        int result = 0;
        for (auto it : mymap) {
            int key = it.first;
            if (key >= 80 || ( mymap.count(getLeftChild(key)) == 0 && mymap.count(getLeftChild(key)+1) == 0)) {
                // this is leaf
                while (mymap.count(key) > 0) {
                    result += mymap[key];
                    int d = key/10;
                    int p = key%10;
                    key = 10*(d-1)+(p+1)/2;
                }
            }
        }
        return result;
    }
};
