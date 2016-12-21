class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<vector<int>> stats(2, vector<int>(32, 0));
        int totalhammingdistance = 0;
        for (int v : nums) {
            for (int i = 0; i < 32; i++, v/=2) {
                int key = v & 0x1;
                totalhammingdistance += stats[1-key][i];
                stats[key][i] ++;
            }
        }
        return totalhammingdistance;
    }
};
