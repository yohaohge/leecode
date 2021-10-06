/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced2(TreeNode* root, int& deepth) 
    {
        if(root == nullptr)
            return true;

        int left = 0;
        int right = 0;

        bool ret = isBalanced2(root->left, left) && isBalanced2(root->right, right);

        if(abs(left - right) > 1)
            ret = false;
        deepth = 1 + max(left, right);
        return ret;    
    }

    bool isBalanced(TreeNode* root) {
        int deep = 0;
        return isBalanced2(root, deep);
    }
};
// @lc code=end

