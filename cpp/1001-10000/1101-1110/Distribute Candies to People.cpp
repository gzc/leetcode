class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int k = 1;
        int index = 0;
        
        while (candies > 0) {
            int c = min(k, candies);
            ans[index] += c;
            k++;
            candies -= c;
            index = (index+1) % num_people;
        }
        
        return ans;
    }
};
