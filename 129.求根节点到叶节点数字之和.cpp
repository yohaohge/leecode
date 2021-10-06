/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    void visit(TreeNode* root, int& sum, int num)
    {
        if(root == nullptr)
            return;
        num = num * 10 + root->val;

        if(root->left == nullptr && root->right == nullptr)
        {
            sum += num;
            return ;
        }

        visit(root->left, sum, num);
        visit(root->right, sum, num);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        visit(root, sum, 0);
        return sum;
    }
};
// @lc code=end

