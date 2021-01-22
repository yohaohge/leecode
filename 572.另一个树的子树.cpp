/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
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
    bool isSame(TreeNode*s, TreeNode* t)
    {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr && t != nullptr) return false;
        if(s != nullptr && t == nullptr) return false;
        if(t->val != s->val) return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr &&t != nullptr) return false;
        if(s != nullptr && t == nullptr) return false;        
        
        if(isSame(s, t)) return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
// @lc code=end

