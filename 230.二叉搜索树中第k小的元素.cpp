/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    void visit(TreeNode* root, int& cnt, int k, int& res)
    {
        if(root == nullptr)
            return;
        visit(root->left, cnt, k, res);
        if(k == cnt)
        {
            res = root->val;
        }
        cnt++;
        if(cnt > k) return;
        visit(root->right, cnt ,k, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int cnt = 1;
        visit(root, cnt, k, res);

        return res;
    }
};
// @lc code=end

