struct point
{
    int i;
    int j;
    int v;
    point(int _i, int _j, int _v):i(_i),j(_j),v(_v){}
};

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (const struct point& lhs, const struct point &rhs) const
    {
        if (reverse) return (lhs.v > rhs.v);
        else return (lhs.v < rhs.v);
    }
};

class Solution {
    
    pair<int,int> cors[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        typedef priority_queue<point, vector<point>, mycomparison> mytype;
        mytype myqueue(mycomparison(true));
        
        int height = rooms.size();
        if(height == 0) return;
        int width = rooms[0].size();
        if(width == 0) return;
        
        for(int j = 0;j < height;j++)
            for(int i = 0;i < width;i++)
                if(rooms[j][i] == 0)
                    myqueue.push(point(i, j, 0));
        
        while(!myqueue.empty())
        {
            struct point p = myqueue.top();
            myqueue.pop();
            
            for(int m = 0;m <= 3;m++)
            {
                int ox = p.i + cors[m].first;
                int oy = p.j + cors[m].second;
                int ov = p.v;
                if(ox >= 0 && ox < width && oy >= 0 && oy < height)
                {
                    if(rooms[oy][ox] == INT_MAX)
                    {
                        rooms[oy][ox] = p.v + 1;
                        myqueue.push(point(ox,oy,rooms[oy][ox]));
                    }
                }
            }
            
        }
        
    }
};
