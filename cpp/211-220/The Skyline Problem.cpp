class Solution {
public:
    struct comp{
        bool operator ()(const int &a, const int &b){ return a > b;}
    };
    
    struct mycomparison{
        bool operator ()(pair<int, int> &a, pair<int, int> &b){ return a.first >= b.first;}
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > ret;
        typedef std::priority_queue<pair<int, int>,std::vector<pair<int, int>>, mycomparison> mypq_type;
        mypq_type points;
        for(auto e : buildings) {
            points.push(make_pair(e[0], e[2]));
            points.push(make_pair(e[1], e[2] * -1));
        }
        multiset<int, comp> sky;
        sky.insert(0);
        while (!points.empty()){
            int last_height = *sky.begin();
            int cur = points.top().first;
            while (!points.empty() && points.top().first == cur){
                int height = points.top().second;
                if (height > 0){
                    sky.insert(height);
                }else{
                    sky.erase(sky.find(height * -1));
                }
                points.pop();
            }
            if (*sky.begin() != last_height){
                ret.push_back(make_pair(cur, *sky.begin()));
            }
        }
        return ret;
    }
};
