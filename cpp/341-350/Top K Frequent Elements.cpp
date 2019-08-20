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


class Solution {
      struct greater_than{
        bool operator() (const pair<int, int>&lhs, const pair<int, int>&rhs) {
            return lhs.second > rhs.second;
        }
      };
public:
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>dict;
        priority_queue<pair<int, int>, vector<pair<int,int>>,greater_than> q;
        vector<int> res(k);
        for(int v : nums) dict[v]++;
        for(const auto &m:dict) {
            q.push({m.first,m.second});
            if(q.size() > k) {
                q.pop();
            }
        }
        while (!q.empty()) {
            res[--k] = q.top().first;
            q.pop();
        }
        return res;
    }
};
