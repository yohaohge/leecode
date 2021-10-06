/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    bool isLeaf(TreeNode* root)
    {
        return root != nullptr && root->left == nullptr && root->right == nullptr;
    }
    int addLeft(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        if(root->left != nullptr && isLeaf(root->left))
        {
            return root->left->val;
        }

        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return addLeft(root) + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
// @lc code=end

