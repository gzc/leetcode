struct Node {
    int state;
    vector<int> edges;
    Node(int x) : state(x) { }
};
 
class Solution {

    vector<struct Node>  Nodes;
    
    bool dfs_visit(int u) {
        Nodes[u].state = 1;
        for (int i = 0;i < Nodes[u].edges.size();i++) {
            int num = Nodes[u].edges[i];
            if(Nodes[num].state == 0) {
                bool fff = dfs_visit(num);
                if(!fff) return false;
            } else if(Nodes[num].state == 1) {
                return false;
            }
        }
        Nodes[u].state = 2;
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Nodes.clear();
        for (int i = 0;i < numCourses;i++)
            Nodes.push_back(Node(0));
        for (int i = 0;i < prerequisites.size();i++)
            Nodes[prerequisites[i].first].edges.push_back(prerequisites[i].second);
        
        for (int i = 0;i < numCourses;i++) {
            vector<int> edges = Nodes[i].edges;
            if(edges.empty()) continue;
            if(Nodes[i].state != 0) continue;
            bool fff = dfs_visit(i);
            if(!fff) return false;
        }
        return true;
    }
};
