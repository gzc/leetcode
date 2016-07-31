class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int result(0), diff(INT_MAX);
        sort(num.begin(), num.end());
        int i(0);
        
        while (i < num.size() - 2)
        {
            int j(i + 1), k(num.size()-1);
            int remain(target - num[i]);
            
            while (j < k)
            {
                int tmp = abs(num[j] + num[k] - remain);
                if (tmp < diff)
                {
                    diff = tmp;
                    result = num[i] + num[j] + num[k];
                }
                
                if (num[j] + num[k] > remain) k--;
                else j++;
            }
            
            do {
                i++;
            }
            while (num[i] == num[i-1]);
        }
        return result;
    }
};
