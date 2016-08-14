struct Node {
    int state;
    vector<int> edges;
    Node(int x) : state(x){}
};

class Solution {
    
    vector<Node>  Nodes;
    
    bool DFS_VISIT(int u, vector<int>& v) {
        Nodes[u].state = 1;
        for (int i = 0;i < Nodes[u].edges.size();i++) {
            int num = Nodes[u].edges[i];
            if (Nodes[num].state == 0) {
                bool fff = DFS_VISIT(num, v);
                if(!fff) return false;
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
        vector<int>empty;
        
        for (int i = 0;i < numCourses;i++)
            Nodes.push_back(Node(0));
        for (int i = 0;i < prerequisites.size();i++)
            Nodes[prerequisites[i].first].edges.push_back(prerequisites[i].second);
        
        for (int i = 0;i < numCourses;i++) {
            vector<int> edges = Nodes[i].edges;
            if (Nodes[i].state != 0) continue;
            if (edges.empty()) {
                orders.push_back(i);
                Nodes[i].state = 2;
                continue;
            }
            bool fff = DFS_VISIT(i, orders);
            if (!fff) return empty;
        }
        return orders;
    }
};
