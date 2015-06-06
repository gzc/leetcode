int gcd(int a, int b) {
        if(b==0) return a;
        else return gcd(b, a%b);
    }

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() <= 2)
            return points.size();
        
        int maxNum = 0;
        
        for(int i = 0;i < points.size();i++)
        {
            int localmax(0),overlap(0),vertical(0);
            map<pair<int, int>,int> statistic;
            for(int j = i+1;j < points.size();j++)
            {
                if(points[j].x==points[i].x && points[j].y==points[i].y) {
                    overlap++;
                    continue;
                }else if(points[j].x==points[i].x) {
                    vertical++;
                }
                else {
                    int x = points[j].x - points[i].x;
                    int y = points[j].y - points[i].y;
                    int divide = gcd(x,y);
                    x /= divide;
                    y /= divide;
                    pair<int, int>p(x,y);
                    statistic[p] += 1;
                    localmax=max(statistic[p], localmax);
                }
            }
            localmax=max(vertical, localmax);
            maxNum=max(maxNum, localmax+overlap+1);
        }
        
        return maxNum;
    }
};
