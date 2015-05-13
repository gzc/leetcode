class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> sets;
        vector<int> empty;
        sets.push_back(empty);
        int num = 1;
        int prev(INT_MIN);
        for(int i = 0;i < nums.size();i++)
        {
            int number = nums[i];
            if(number != prev)
            {
                num = sets.size();
                for(int k = 0;k < num;k++)
                {
                    vector<int> tmp = sets[k];
                    tmp.push_back(number);
                    sets.push_back(tmp);
                }
                prev = number;
            } else {
                int index = sets.size()-num;
                for(int k = 0;k < num;k++)
                {
                    vector<int> tmp = sets[k+index];
                    tmp.push_back(number);
                    sets.push_back(tmp);
                }
            }
        }
        return sets;
        
    }
};
