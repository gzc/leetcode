class Solution {
    
public:
    string largestNumber(vector<int> &num) {
        
        auto cmp = [&] (const string& lhs, const string& rhs) {
            return lhs+rhs < rhs+lhs;
        };
        
        typedef std::priority_queue<string, std::vector<string>, decltype(cmp)> mypq_type;
        mypq_type pq (cmp);
        
        for(int i = 0;i < num.size();i++)
            pq.push(to_string(num[i]));
        
        string result("");
        while (!pq.empty()) {
            result = result + pq.top();
            pq.pop();
        }
        
        while(result.length() > 1 && result[0] == '0')
            result = result.substr(1);
        
        return result;
    }
};
