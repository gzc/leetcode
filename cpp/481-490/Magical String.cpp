class Solution {
public:
    int magicalString(int n) {
        if (n <= 3)
            return n > 0;
        queue<int> q;
        int res = 1;
        bool one = true;
        q.push(2);
        n -= 3; //122, start from second 2
        while (n) {
            int cnt = q.front();
            q.pop();
            while (n && cnt--) {
                q.push(one ? 1 : 2);
                n--;
                res += one;
            }
            one = !one;
        }
        return res;
    }
};
