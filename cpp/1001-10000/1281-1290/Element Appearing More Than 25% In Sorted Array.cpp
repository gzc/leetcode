class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int pv = arr[0]-1;
        int times = 0;
        for (int v : arr) {
            if (v == pv) {
                times++;
                if (times >= arr.size()/4) return v;
            } else {
                times = 0;
                pv = v;
            }
        }
        return arr.back();
    }
};
