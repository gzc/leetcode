class Solution {
private:
    struct mycompare{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int,int>, vector<pair<int, int> >, mycompare> pq;
        for(int num1 : nums1){
            for(int num2 : nums2){
                pq.push(make_pair(num1, num2));
                if(pq.size() > k) pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
