/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        // if(root == nullptr)
        //     return 0;
        // int left = minDepth(root->left);
        // int right = minDepth(root->right);
        // if(left == 0) return  right + 1;
        // if(right == 0) return left + 1;
        // return min(left, right) + 1;

        return root == nullptr ? 0 : 1 + (root->left == nullptr ? minDepth(root->right) : (root->right == nullptr ?  minDepth(root->left) : min(minDepth(root->right), minDepth(root->left))));
    }
};
// @lc code=end

