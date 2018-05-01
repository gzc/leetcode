class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int sum = accumulate(machines.begin(), machines.end(), 0);
        
        if (sum % n != 0) return -1;
        int avg = sum / n;
        int ans = 0;
        int peak = 0;
        
        for (int machine : machines) {
            peak = peak + machine - avg;
            ans = max(ans, abs(peak));
            ans = max(ans, machine - avg);
                      
        }
        return ans;
    }
};
