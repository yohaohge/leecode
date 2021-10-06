/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* build(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return nullptr;
        
        int iMax = start;
        for(int i = start; i <= end; i++)
        {
            if(nums[iMax] < nums[i])
                iMax = i;
        }
        TreeNode* node = new TreeNode(nums[iMax]);

        node->left = build(nums, start, iMax - 1);
        node->right = build(nums, iMax + 1, end);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

