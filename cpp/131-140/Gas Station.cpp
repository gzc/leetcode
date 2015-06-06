class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totalSum(0), start(0), now(0);
        
        for(int i = 0;i < gas.size();i++)
        {
            int tmp = gas[i] - cost[i];
            totalSum += tmp;
            now += tmp;
            if(now < 0)
            {
                start = i+1;
                now = 0;
            }
        }
        
        return totalSum >= 0 ? start : -1;
    }
};
