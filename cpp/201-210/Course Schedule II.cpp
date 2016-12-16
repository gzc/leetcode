struct Node {
    int state;
    vector<int> edges;
    Node() : state(0) { }
};

class Solution {
    
    vector<Node>  Nodes;
    
    bool DFS_VISIT(int u, vector<int>& v) {
        Nodes[u].state = 1;
        for (int i = 0;i < Nodes[u].edges.size();i++) {
            int num = Nodes[u].edges[i];
            if (Nodes[num].state == 0) {
                bool hascircle = !DFS_VISIT(num, v);
                if(hascircle) return false;
            } else if (Nodes[num].state == 1) {
                return false;
            }
        }
        Nodes[u].state = 2;
        v.push_back(u);
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>orders;
        Nodes.resize(numCourses);
        
        for (int i = 0;i < prerequisites.size();i++)
            Nodes[prerequisites[i].first].edges.push_back(prerequisites[i].second);
        
        for (int i = 0;i < numCourses;i++) {
            if (Nodes[i].state != 0) continue;
            bool hascircle = !DFS_VISIT(i, orders);
            if (hascircle) return vector<int>();
        }
        return orders;
    }
};
