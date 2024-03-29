/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    long sum(TreeNode* root, long long& res)
    {
        if(root == nullptr)
            return 0;
        long long left = sum(root->left, res);
        long long right = sum(root->right, res);
        res += abs(left-right);
        return left + right + root->val;
    }

    int findTilt(TreeNode* root) {
        long long res = 0;
        if(root)
        {
            sum(root, res);
        }
        return res;

    }
};
// @lc code=end

