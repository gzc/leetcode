class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        
        vector<int> delicious_vec;
        int base = 1;
        for (int i = 0; i <= 21; i++) {
            delicious_vec.push_back(base);
            base *= 2;
        }
        reverse(delicious_vec.begin(), delicious_vec.end());
        
        unordered_map<int, int> mymap;
        long answer = 0;
        for (int d : deliciousness) {
            
            for (int sum : delicious_vec) {
                
                int target = sum - d;
                if (target < 0) break;
                answer += mymap[target];
            }
            
            mymap[d]++;
        }
        
        long mod = 1e9+7;
        answer = answer % mod;
        return answer;
    }
};
