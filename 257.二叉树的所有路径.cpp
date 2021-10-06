/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void visit(vector<string>& res, string cur, TreeNode* root)
    {
        if(root == nullptr)
        {
            if(cur.length())
            return;
        }

        if(cur.length())
        {
            cur = cur + "->" + to_string(root->val);
        }
        else
        {
            cur = to_string(root->val);
        }

        if(root->left == nullptr && root->right == nullptr)
        {
            res.push_back(cur);
            return;
        }

        visit(res, cur, root->left);
        visit(res, cur, root->right);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        visit(res, "", root);

        return res;
    }
};
// @lc code=end

