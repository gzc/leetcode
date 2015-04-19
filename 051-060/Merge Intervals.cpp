#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
  };
 

bool compareInterval(Interval a, Interval b)
{
    return (a.start<b.start);
}

class Solution {
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        
        if(intervals.size() < 2)
            return intervals;
        
        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),compareInterval);
        
        Interval now = intervals[0];
        for(int i = 1;i < intervals.size();i++)
        {
            Interval then = intervals[i];
            
            if(now.end >= then.start)
            {
                now.end = max(now.end, then.end);
            } else {
                result.push_back(now);
                now = then;
            }
            
            
        }
        result.push_back(now);
        return result;
    }
    
};

int main()
{
    Solution s;
    
    return 0;
}