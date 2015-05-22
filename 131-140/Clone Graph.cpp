class Solution {
    
    map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if(!node) return nullptr;
        if(m.find(node) == m.end())
        {
            m[node] = new UndirectedGraphNode(node->label);
            for(auto n : node->neighbors)
                m[node]->neighbors.push_back(cloneGraph(n));
        }
        return m[node];
    }
};
