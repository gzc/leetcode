struct Node {
    int state;
    vector<int> edges;
    Node() : state(0) { }
};
 
class Solution {

    vector<struct Node>  Nodes;
    
    bool dfs_visit(int u) {
        Nodes[u].state = 1;
        for (int i = 0;i < Nodes[u].edges.size();i++) {
            int num = Nodes[u].edges[i];
            if(Nodes[num].state == 0) {
                bool hascircle = !dfs_visit(num);
                if(hascircle) return false;
            } else if(Nodes[num].state == 1) {
                return false;
            }
        }
        Nodes[u].state = 2;
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        Nodes.resize(numCourses);
        for (int i = 0;i < prerequisites.size();i++)
            Nodes[prerequisites[i].first].edges.push_back(prerequisites[i].second);
        
        for (int i = 0;i < numCourses;i++) {
            bool hascircle = !dfs_visit(i);
            if(hascircle) return false;
        }
        return true;
    }
};
