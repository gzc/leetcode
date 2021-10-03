/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // rule:  root, number of child, each child
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string data;
        encode_dfs(root, data);
        return data;
    }

    void encode_dfs(Node* root, string& data){
        if (root == nullptr) return;
        data += to_string(root->val) + " " + to_string(root->children.size()) + " ";
        for (Node* child : root->children) {
            encode_dfs(child, data);
        }
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    
    Node* decode(stringstream& ss) {
        int val, child_size;
        if (ss >> val >> child_size) {
            Node* root = new Node(val);
            for (int i = 0; i < child_size; i++) {
                root->children.push_back(decode(ss));
            }
            return root;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
