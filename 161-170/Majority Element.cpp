class Solution {
public:
    int majorityElement(vector<int> &num) {
        stack<int> s;
        for(int i = 0;i < num.size();i++)
        {
            if(s.empty())
                s.push(num[i]);
            else{
                int t = s.top();
                if(t != num[i])
                    s.pop();
                else
                    s.push(num[i]);
            }
        }
        return s.top();
    }
};
