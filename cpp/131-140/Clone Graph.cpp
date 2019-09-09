/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> dict;
public:
    
    Node* cloneGraph(Node* node) {
        //if (!node) return nullptr;
        if (dict.count(node) == 0) {
            dict[node] = new Node();
            dict[node]->val = node->val;
            for (Node* neighbor : node->neighbors) {
                dict[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return dict[node];
    }
};
