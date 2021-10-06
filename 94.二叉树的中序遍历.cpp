/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void inorderTraversal(TreeNode* root,vector<int>& res)
    {
        if(root == nullptr) return;
        inorderTraversal(root->left,res);
        res.push_back(root->val);
        inorderTraversal(root->right,res);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> res;
        // inorderTraversal(root, res);
        // return res;

        

        // vector<int> res;
        // if(root == nullptr) return res;
        // stack<TreeNode*> s;
        // s.push(root);
        // auto cur = root->left;
        // while(s.size()||cur)
        // {
        //     if(cur)
        //     {
        //         s.push(cur);
        //         cur =  cur->left;
        //     }
        //     else
        //     {
        //         res.push_back(s.top()->val);
        //         cur = s.top()->right;
        //         s.pop();
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
            if(cur && cur->left)
            {
                s.push(cur->left);
                cur = cur->left;
            }
            else
            {
                cur = s.top(); 

                if(cur->right  && per != cur->right)
                {
                    res.push_back(cur->val);
                    per = cur->right;
                    s.push(cur->right);
                    cur = cur->right;
                }
                else
                {
                    if(cur->right == nullptr) res.push_back(cur->val);
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

