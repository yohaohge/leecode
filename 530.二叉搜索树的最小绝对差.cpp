/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void visit(TreeNode* root, int& res, int& prev)
    {
        if(root == nullptr)
            return;
        visit(root->left, res, prev);
        res = min(res, abs(prev - root->val));
        prev = root->val;
        visit(root->right, res, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int prev = INT_MAX/2;

        visit(root, res, prev);

        return res;
    }
};
// @lc code=end

