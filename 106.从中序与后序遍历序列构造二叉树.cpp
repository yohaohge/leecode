/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* reBuildTree(vector<int>& inorder, int inStart, int inEnd, 
                          vector<int>& postorder, int postStart, int postEnd) {
        if(inEnd < inStart)
            return nullptr;
        if(inStart == inEnd)
            return new TreeNode(inorder[inStart]);

        int target = postorder[postEnd];
        int i;
        for(i = inStart; i <= inEnd; i++)
        {
            if(inorder[i] == target) break;
        } 
        
        // size of left sub tree
        int len = i - inStart - 1;

        TreeNode* root = new TreeNode(target);
        // left
        root->left = reBuildTree(inorder, inStart, i - 1, postorder, postStart, postStart + len);
        // right
        root->right = reBuildTree(inorder, i + 1, inEnd, postorder, postStart + len + 1, postEnd - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return reBuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
// @lc code=end

