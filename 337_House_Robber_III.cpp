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
    int rob(TreeNode* root) {
        //return rob_rec(root);
        unordered_map<TreeNode*, int> dp;
        return rob_topdown(root, dp);
    }

    int rob_rec(TreeNode* root)
    {
        if (!root) return 0;

        int t2 = rob_rec(root->left) + rob_rec(root->right);

        int t1 = root->val;
        if (root->left) t1 += rob_rec(root->left->left) + rob_rec(root->left->right);
        if (root->right) t1 += rob_rec(root->right->left) + rob_rec(root->right->right);

        return max(t1, t2);
    }

    int rob_topdown(TreeNode* root, unordered_map<TreeNode*, int>& dp)
    {
        if (!root) return 0;
        if (dp.find(root) != dp.end()) return dp[root];
        int t2 = rob_topdown(root->left, dp) + rob_topdown(root->right, dp);

        int t1 = root->val;
        if (root->left) t1 += rob_topdown(root->left->left, dp) + rob_topdown(root->left->right, dp);
        if (root->right) t1 += rob_topdown(root->right->left, dp) + rob_topdown(root->right->right, dp);

        dp[root] = max(t1, t2);
        return dp[root];
    }

};
