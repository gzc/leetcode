class Solution {
    
    struct greater_than
    {
        inline bool operator() (const pair<int, int>& left, const pair<int, int>& right)
        {
            return (left.second > right.second);
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mymap;
        vector<pair<int, int> > myvec;
        for(int ele : nums) mymap[ele] += 1;
        for(auto ele : mymap) myvec.push_back(make_pair(ele.first, ele.second));
        sort(myvec.begin(), myvec.end(), greater_than());
        
        vector<int> result;
        for(int i = 0;i < k;i++)
            result.push_back(myvec[i].first);
        return result;
    }
};
