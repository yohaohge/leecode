/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr) return right == nullptr;
        if(right == nullptr) return left == nullptr;

        if(left->val == right->val)
        {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left) ;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return isSymmetric(root->left, root->right);
    }
};
// @lc code=end

