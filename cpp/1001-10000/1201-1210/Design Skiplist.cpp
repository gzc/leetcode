class Skiplist {
    
    struct Node {
        Node *right, *down;
        int val;
        Node(Node *right, Node *down, int val): right(right), down(down), val(val) {}
    };
    
    Node* head;
    
public:
    Skiplist() {
        head = new Node(nullptr, nullptr, -1);
    }
    
    bool search(int num) {
        Node *cur = head;
        while (cur != nullptr) {
            while (cur->right != nullptr && cur->right->val < num) {
                cur = cur->right;
            }
            
            if (cur->right == nullptr || cur->right->val > num) {
                cur = cur->down;
            } else {
                return true;
            }
        }
        return false;
    }
    
    void add(int num) {
        stack<Node*> insertPoints;
        Node *cur = head;
        while (cur != nullptr) {
            while (cur->right != nullptr && cur->right->val < num) {
                cur = cur->right;
            }
            insertPoints.push(cur);
            cur = cur->down;
        }
        
        Node* downNode = nullptr;
        bool insertUp = true;
        while (insertUp && !insertPoints.empty()) {
            Node *ins = insertPoints.top();
            insertPoints.pop();
            
            ins->right = new Node(ins->right, downNode, num);
            downNode = ins->right;
            
            insertUp = ((rand() & 1) == 0);
        }
        
        if (insertUp) {
            head = new Node(new Node(NULL, downNode, num), head, -1);
        }
    }
    
    bool erase(int num) {
        Node *cur = head;
        bool seen = false;
        while (cur != nullptr) {
            while (cur->right != nullptr && cur->right->val < num) {
                cur = cur->right;
            }
            
            if (cur->right == nullptr || cur->right->val > num) {
                cur = cur->down;
            } else {
                seen = true;
                Node* to_delete = cur->right;
                cur->right = cur->right->right;
                cur = cur->down;
                delete to_delete;
            }
        }
        return seen;
    }
};
