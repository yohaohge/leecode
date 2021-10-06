/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> tmp;
        while(!q.empty())
        {
            int len = q.size();
            while(len--)
            {   
                if(q.front())
                {
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                    tmp.push_back(q.front()->val);
                }
                q.pop();
            }
            if(tmp.size() > 0)
                res.push_back(tmp);
            tmp.clear();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

