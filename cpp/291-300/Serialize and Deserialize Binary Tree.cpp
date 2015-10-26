/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
    void readNext(stringstream& ss, int& val, bool &isnumber) {
        string str;
        ss >> str;
        if(str[0] == '#') {
            isnumber = false;
        } else {
            val = stoi(str);
            isnumber = true;
        }
        return;
    }
    
    TreeNode* help(stringstream& ss) {
        bool isnumber;
        int val;
        TreeNode *root(nullptr);
        readNext(ss, val, isnumber);
        
        if(isnumber) {
            root = new TreeNode(val);
            root->left = help(ss);
            root->right = help(ss);
        }
        return root;
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "# ";
        else return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return help(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));