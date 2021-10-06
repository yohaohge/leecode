/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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

    void visit(TreeNode* root, int& sum)
    {
        if(root == nullptr)
            return;
        visit(root->right, sum);
        root->val += sum;
        sum = root->val;
        visit(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        int sum = 0;
        visit(root, sum);
        return root;
    }
};
// @lc code=end

