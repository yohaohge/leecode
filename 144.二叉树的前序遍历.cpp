/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> s;
    
        s.push(root);
        TreeNode* per = root;
        TreeNode* cur = root;
        res.push_back(cur->val);
        while(s.size())
        {   
            if(cur && cur->left)
            {
                s.push(cur->left);
                cur = cur->left;
                res.push_back(cur->val);
            }
            else
            {
                cur = s.top();
                if(cur->right  && per != cur->right)
                {
                    per = cur->right;
                    s.push(cur->right);

                    cur = cur->right;
                    res.push_back(cur->val);
                }
                else
                {
                    per = cur;
                    s.pop();
                    cur = nullptr;
                }
                
            }
            
        }

        return res;
    }
};
// @lc code=end

