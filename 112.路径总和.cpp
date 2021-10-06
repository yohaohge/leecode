/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool check(TreeNode* root, int target, int sum)
    {
        if(root == nullptr)
            return false;
        if(root->left == nullptr && root->right == nullptr)
            return root->val + sum == target;
        
        return check(root->left, target, sum + root->val)
               || check(root->right, target, sum + root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return check(root, targetSum, 0);
    }
};
// @lc code=end

