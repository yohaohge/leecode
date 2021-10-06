/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
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
    int visit(TreeNode* root, int& res)
    {
        if(root == nullptr)
            return 0;
        int left = visit(root->left, res);
        int right = visit(root->right, res);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        if(root)
            visit(root, res);
        return res;
    }
};
// @lc code=end

