class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, int> mymap;
        for (int v : nums) {
            if (mymap.count(v) > 0) {
                continue;
            }
            mymap[v] = 1;
            
            int end = v;
            int begin = v;
            if(mymap.count(v + 1) > 0) {
                end = v + mymap[v + 1];
            }
            if(mymap.count(v - 1) > 0) {
                begin = v - mymap[v - 1];
            }
            
            longest = max(longest, end - begin + 1);
            mymap[end] = end - begin + 1;
            mymap[begin] = end - begin + 1;
        }
        
        return longest;
    }
};
