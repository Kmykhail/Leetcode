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
    int helper(int res, TreeNode *root) {
        if (!root) return 0;
        
        res = res * 10 + root->val;
        if (!root->left && !root->right) return res;
        
        return helper(res, root->left) + helper(res, root->right);
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(0, root);
    }
};
