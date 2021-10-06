/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    int depth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        return max(depth(root->left), depth(root->right)) + 1;
    }
    void visit(TreeNode* root, int i, int j, vector<vector<string>>& res, int w)
    {
        if(root == nullptr)
            return ;
        res[i][j] = to_string(root->val);
        visit(root->left, i + 1, j - w/2 - 1, res, w/2);
        visit(root->right, i + 1, j + w/2 + 1, res, w/2);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int d = depth(root);
        int w = (1 << d) - 1;
        vector<vector<string>> res(d, vector<string>(w, ""));
        
        visit(root, 0, w/2, res, w/2);
        return res;
    }
};
// @lc code=end

