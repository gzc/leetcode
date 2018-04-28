class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > ret;
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b){ return a.first >= b.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> points(cmp);
        for(const auto& e : buildings) {
            points.push(make_pair(e[0], e[2]));
            points.push(make_pair(e[1], e[2] * -1));
        }
        multiset<int, std::greater<int>> sky;
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
