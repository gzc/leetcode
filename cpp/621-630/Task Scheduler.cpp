class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mymap;
        int maximumTimes = 0;
        for (char ch : tasks) {
            mymap[ch]++;
            maximumTimes = max(maximumTimes, mymap[ch]);
        }
        
        int ans = (maximumTimes -  1) * (n + 1);
        
        for (const auto& ele : mymap) {
            if (maximumTimes == ele.second) {
                ans++;
            }
        }
        
        return max(int(tasks.size()), ans);
    }
};
