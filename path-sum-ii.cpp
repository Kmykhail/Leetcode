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

    void rec_func(TreeNode *root, vector<vector<int>> &res, vector<int> cur, int targetSum) {
        if (!root) return;
        
        cur.emplace_back(root->val);

        if (root->val == targetSum && (!root->left && !root->right)) {
            res.emplace_back(cur);
            return;
        }
        
        rec_func(root->left, res, vector<int>(cur), targetSum - root->val);
        rec_func(root->right, res, vector<int>(cur), targetSum - root->val);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};

        vector<vector<int>> res;
        
        rec_func(root, res, {}, targetSum);
        
        return res;
    }
};
