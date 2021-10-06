/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    int getDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr)
            return nullptr;
        int srcDepth = getDepth(root);
        if(depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
       
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(q.size())
        {
            int len = q.size();

            while(len--)
            {
         

                if(q.front()->left)
                {
                    q.push(q.front()->left);
             
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }

                if(i == depth - 1)
                {
                    TreeNode *node = new TreeNode(val);
                    node->left = q.front()->left;
                    q.front()->left = node;

                    node = new TreeNode(val);
                    node->right = q.front()->right;
                    q.front()->right = node;
                }
                q.pop();
            }
            i++;
        }

        return root;
    }
};
// @lc code=end

