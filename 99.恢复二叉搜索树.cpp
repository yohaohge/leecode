/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    * };
 */
class Solution {
public:
    void visit(TreeNode* root, TreeNode*& prev, TreeNode*& first,  TreeNode*& end)
    {
        if(root == nullptr)
            return;
        visit(root->left, prev, first, end);
        // 中序遍历
        if(prev != nullptr && prev->val > root->val)
        {
            if(first == nullptr)
                first = prev;
            end = root;
        }
        prev = root;
        visit(root->right, prev, first, end);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* end = nullptr;

        visit(root, prev, first, end);
        swap(first->val, end->val);
    }
};
// @lc code=end

