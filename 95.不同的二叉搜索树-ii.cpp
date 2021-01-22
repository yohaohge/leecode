/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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

    vector<TreeNode*> generateTrees(int n, int start)
    {
        vector<TreeNode*> res;
        if(n == 0) {
            res.push_back(nullptr);
            return res;
        }
        if(n == 1) {
            TreeNode* node = new TreeNode(start);
            res.push_back(node);
            return res;
        }

        for(int i = 0; i < n; i++)
        {
            vector<TreeNode*> left = generateTrees(i,start);
            vector<TreeNode*> right = generateTrees( n - i -1, start+i+1);

            for(auto pLeft: left)
            {
                for(auto pRight: right)
                {
                    TreeNode* root = new TreeNode(start+i);
                    root->left = pLeft;
                    root->right = pRight;
                    res.push_back(root);
                }
            }

        }

        return res;

    }

    vector<TreeNode*> generateTrees(int n) {
        if(n > 0)
            return generateTrees(n, 1);
        else
        {
            vector<TreeNode*> res;
            return res;
        }
        
    }
};
// @lc code=end

