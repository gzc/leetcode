class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int dis_a = 0;
        int dis_b = 0;
        int n = distance.size();
        
        int s = start;
        int d = destination;
        while (s != d) {
            dis_a += distance[s];
            s = (s+1) % n;
        }
        
        s = start; d = destination;
        while (s != d) {
            s = ( (s-1) + n) % n;
            dis_b += distance[s];
        }
        
        return min(dis_a, dis_b);
    }
};
