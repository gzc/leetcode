class Solution {

  void inorder(Node* cur, Node*& prev, Node*& head) {
        if (head == nullptr && cur->left == nullptr) {
            head = cur;
        }
        Node* left = cur->left;
        Node* right = cur->right;

        if (left != nullptr) {
            inorder(left, prev, head);
        }

        if (prev != nullptr) {
            prev->right = cur;
        }
        cur->left = prev;

        prev = cur;
        if (right != nullptr) {
            inorder(right, prev, head);
        }
    }

public:
    
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* prev = nullptr;
        Node* head = nullptr;
        inorder(root, prev, head);
        
        prev->right = head;
        head->left = prev;
        
        return head;
    }
};
