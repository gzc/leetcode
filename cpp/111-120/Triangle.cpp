class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        
        // Dp method, record the minimum value for that position
        vector<int> dp {triangle[0][0]};
        
        for (int i = 1; i < triangle.size(); i++) {
            vector<int> temp(dp.size() + 1);
            for (int j = 0; j < triangle[i].size(); j++) {
                if(j == 0) {
                    temp[j] = triangle[i][j] + dp.front();
                } else if(j == triangle[i].size()-1) {
                    temp[j] = triangle[i][j]+dp.back();
                } else {
                    temp[j] = triangle[i][j] + min(dp[j-1], dp[j]);
                }
            }
            // swap if faster than dp = temp
            dp.swap(temp);
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
