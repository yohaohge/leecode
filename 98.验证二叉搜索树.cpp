/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root, long long maxVal, long long minVal)
    {
        if(root == nullptr) return true;

        if(root->val >= maxVal) return false;
        if(root->val <= minVal) return false;

        bool left = isValidBST(root->left, root->val, minVal);
        bool right = isValidBST(root->right,maxVal,root->val);

        return  left && right;
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MAX, LLONG_MIN); 
    }
};
// @lc code=end

