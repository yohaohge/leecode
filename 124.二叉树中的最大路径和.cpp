/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    
    // 当前节点位起点的最大值
    int visit(TreeNode* root, int& maxres)
    {
        if(root == nullptr)
            return 0;
        int left = visit(root->left, maxres);
        int right = visit(root->right, maxres);
        int maxcur = root->val + max(0, left) + max(0, right);
        maxres = max(maxres, maxcur);
        return root->val + max(max(left, right),0) ;
    }

    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int res = root->val;
        visit(root, res);
        return res;
    }
};
// @lc code=end

