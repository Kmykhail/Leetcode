/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> m_stack;
        
        m_stack.push(root);

        TreeNode *x = nullptr;
        
        while ( !m_stack.empty() ) {
            auto node = m_stack.top();
            m_stack.pop();

            if (x) {
                x->right = node;
                x = nullptr;
            }
            
            auto l_tmp = node->left;
            node->left = nullptr;
            
            auto r_tmp = node->right;
            if (l_tmp) node->right = l_tmp;

            if (r_tmp) m_stack.push(r_tmp);
            if (l_tmp) m_stack.push(l_tmp);
            
            if (!r_tmp && !l_tmp) x = node;
        }
    }
};
