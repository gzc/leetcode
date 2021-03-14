/*
 * Solution 1
 * Use to_string to convert integer to a string.
 * Use space to separate each node.
 * Write a '#' for nullptr node.
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
        TreeNode *root = nullptr;
        readNext(ss, val, isnumber);
        
        if (isnumber) {
            root = new TreeNode(val);
            root->left = help(ss);
            root->right = help(ss);
        }
        return root;
    }
    
    // Encodes a tree to a single string.
    string _serialize(TreeNode* root) {
        if (root == nullptr) return "# ";
        else return to_string(root->val) + " " + _serialize(root->left) + _serialize(root->right);
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized_data = _serialize(root);
        return serialized_data;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return help(ss);
    }
};


/*
 * Solution 2
 * Write 4 bytes for each integer.
 * Write a 'Y' or 'N' for each node. No separator is need.
 */
class Codec {
    
    void preorderDFS(TreeNode* root, string& serialized_data) {
        if (root == nullptr) {
            serialized_data.push_back('Y');
            return;
        }
        serialized_data.push_back('N');
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int));
        for (int i = 0; i < 4; i++) serialized_data.push_back(buf[i]);
        preorderDFS(root->left, serialized_data);
        preorderDFS(root->right, serialized_data);
    }
    
    inline TreeNode* reconstruct(const string& buffer, int& pos) {
        if (pos >= buffer.size()) return nullptr;
        
        char indicator = buffer[pos];
        pos++;
        
        if (indicator == 'Y') {
            return nullptr;
        }
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos);
        node->right = reconstruct(buffer, pos);
        return node;
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized_data;
        preorderDFS(root, serialized_data);
        return serialized_data;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos);
    }
};
