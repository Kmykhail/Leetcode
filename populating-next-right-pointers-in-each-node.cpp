/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return {};
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            
            int cur_size = q.size();
            
            Node* bridge_ptr = nullptr;
            
            for (int i = 0; i < cur_size; ++i) {
                auto node = q.front();
                q.pop();
                
                if (!node->left) continue; // perfect binary tree where all leaves are on the same level
                
                node->left->next = node->right;
                if (bridge_ptr) {
                    bridge_ptr->next = node->left;
                }
                
                bridge_ptr = node->right;
                
                q.push(node->left);
                q.push(node->right);
            }
        }

        return root;
    }
};
