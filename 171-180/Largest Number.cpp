class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const string& lhs, const string&rhs) const
  {
     string s1 = lhs+rhs;
     string s2 = rhs+lhs;
     return s1  <= s2;
  }
};


class Solution {
    typedef std::priority_queue<string,std::vector<string>,mycomparison> mypq_type;
    
public:
    string largestNumber(vector<int> &num) {
        
        mypq_type pq (mycomparison(true));   // greater-than comparison
        
        for(int i = 0;i < num.size();i++)
            pq.push(to_string(num[i]));
        
        string result("");
        while(!pq.empty())
        {
            result = result + pq.top();
            pq.pop();
        }
        
        while(result.length() > 1 && result[0] == '0')
            result = result.substr(1);
        
        return result;
    }
};
