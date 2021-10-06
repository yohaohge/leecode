/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    unordered_set<int> set;

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr)
            return false;
  
        bool res = findTarget(root->left, k);
        if(res) return true;
        if(set.find(k - root->val) != set.end())
            return true;
        set.insert(root->val);
        res = findTarget(root->right, k);
        return res;
    }
};
// @lc code=end

