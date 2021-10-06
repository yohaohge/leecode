/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    int findLeftMaxValue(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        if(root->right)
            return findLeftMaxValue(root->right);
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if(root->left == nullptr)
                return root->right;
            if(root->right == nullptr)
                return root->left;
            root->val = findLeftMaxValue(root->left);
            root->left = deleteNode(root->left, root->val);
        }

        return root;
    }
};
// @lc code=end

