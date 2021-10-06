/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode* deal(TreeNode* root)
    {
        if(root == nullptr)
            return nullptr;
        TreeNode* right = deal(root->right);
        TreeNode* left = deal(root->left);

        root->right = left;
        root->left = nullptr;

        left = root;
        while(left->right)
            left = left->right;
        left->right = right;
    
        return root;
    }
    void flatten(TreeNode* root) {
       deal(root);
    }
};
// @lc code=end

