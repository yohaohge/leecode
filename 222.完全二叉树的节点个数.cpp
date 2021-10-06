/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int deep(TreeNode* root)
    {
        int res = 0;
        while(root)
        {
            res++;
            root = root->left;
        }
        return res;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr)
            return 1;
        int hl = deep(root->left);
        int hr = deep(root->right);

        if(hl == hr)
            return 1 + (1 << (hl)) - 1 + countNodes(root->right);
        else
            return 1 + (1 << (hr)) - 1 + countNodes(root->left);
    }
};
// @lc code=end

