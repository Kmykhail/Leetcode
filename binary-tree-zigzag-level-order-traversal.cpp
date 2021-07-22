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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<vector<int>> res;

        q.push(root);

        for (int lvl = 0; !q.empty(); ++lvl) {
            vector<int> x;
            auto cur_size = q.size();

            for (int i = 0; i < cur_size; ++i) {
                const auto node = q.front();
                q.pop();

                x.emplace_back(node->val);

                if (!node->left && !node->right) continue;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (lvl % 2 > 0) {
                res.push_back({x.rbegin(), x.rend()});
            } else {
                res.push_back(move(x));
            }
        }

        return res;
    }
};