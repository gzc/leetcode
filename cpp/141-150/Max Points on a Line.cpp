/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
int gcd(int a, int b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() <= 2)
            return points.size();
        
        int maxNum = 0;
        
        for(int i = 0;i < points.size();i++)
        {
            int localmax(0),overlap(0);
            map<pair<int, int>,int> statistic;
            for(int j = i+1;j < points.size();j++)
            {
                //if(j == i) continue;
                if(points[j].x==points[i].x && points[j].y==points[i].y) {
                    overlap++;
                    continue;
                } else {
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
            maxNum=max(maxNum, localmax+overlap+1);
        }
        
        return maxNum;
    }
};