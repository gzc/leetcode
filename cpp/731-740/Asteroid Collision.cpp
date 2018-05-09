class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> mystack;
        for (int ast : asteroids) {
            bool eat = false;
            while (!mystack.empty() && ast < 0 && 0 < mystack.top()) {
                if (mystack.top() < -ast) {
                    mystack.pop();
                    continue;
                } else if (mystack.top() == -ast) {
                    eat = true;
                    mystack.pop();
                } else {
                    eat = true;
                }
                break;
            }
            if (!eat) mystack.push(ast);
        }

        vector<int> ans(mystack.size());
        for (int t = ans.size() - 1; t >= 0; --t) {
            ans[t] = mystack.top();
            mystack.pop();
        }
        return ans;
    }
};
