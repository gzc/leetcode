class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        
        vector<int> v1;
        v1.push_back(triangle[0][0]);
        
        for(int i = 1;i < triangle.size();i++)
        {
            vector<int> v2;
            for(int j = 0;j < triangle[i].size();j++)
            {
                if(j == 0)
                {
                    v2.push_back(triangle[i][j]+v1.front());
                } else if(j == triangle[i].size()-1) {
                    v2.push_back(triangle[i][j]+v1.back());
                } else {
                    v2.push_back(triangle[i][j] + min(v1[j-1], v1[j]));
                }
            }
            v1 = v2;
        }
        
        return *min_element(v1.begin(), v1.end());
    }
};
