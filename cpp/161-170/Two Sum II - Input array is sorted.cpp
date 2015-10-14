class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i(0),j(numbers.size()-1);
        vector<int> result;
        
        while(j > i)
        {
            int sum = numbers[i] + numbers[j];
            if(sum == target)
            {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
            else if(sum > target)
                j--;
            else
                i++;
        }
        
    }
};