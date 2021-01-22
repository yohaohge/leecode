/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;
        // if(root == nullptr) return res;
        // stack<TreeNode*> s;
    
        // s.push(root);
        // TreeNode* per = root;
        // TreeNode* cur = root;

        // while(s.size())
        // {   
        //     if(cur && cur->left)
        //     {
        //         s.push(cur->left);
        //         cur = cur->left;
        //     }
        //     else
        //     {
        //         cur = s.top();
        //         if(cur->right  && per != cur->right)
        //         {
        //             per = cur->right;
        //             s.push(cur->right);
        //             cur = cur->right;
                    
        //         }
        //         else
        //         {
        //             res.push_back(cur->val);
        //             per = cur;
        //             s.pop();
        //             cur = nullptr;
        //         }
                
        //     }
            
        // }


        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> s;
    
        s.push(root);
        TreeNode* per = root;
        TreeNode* cur = root;

        while(s.size())
        {
            cur = s.top();
            if(cur->left && cur->left != per && per != cur->right) 
            {
                s.push(cur->left);
            }
            else if(cur->right && per != cur->right)
            {
                s.push(cur->right);
            }
            else
            {
                res.push_back(cur->val);
                per = cur;
                s.pop();
            }
            
            
        }


        return res;
    }
};
// @lc code=end

