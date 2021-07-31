class Solution{
  public:

    Node *getNode(Node * root) {
        return (!root->left) ? root : getNode(root->left);
    }

    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if (!root || !x) return nullptr;

        if (x->right) return getNode(x->right);   
        
        Node *successor {nullptr};
        
        while (root) {
            
            if (root->data == x->data) {
                root = root->right;
                continue;
            }
            
            if (root->data > x->data) {
                if (!successor || root->data < successor->data) {
                    successor = root;
                }
            }
            
            if (x->data < root->data) root = root->left;
            if (x->data >= root->data) root = root->right;
        }
        
        return successor;
    }
};
