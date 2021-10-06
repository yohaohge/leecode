/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;

        stack<TreeNode*> q;
        stack<TreeNode*> s;

        q.push(root);
        vector<int> tmp;

        while(!q.empty() || !s.empty())
        {
            tmp.clear();
            while(!q.empty())
            {
                if(q.top() != nullptr)
                {
                    s.push(q.top()->left);
                    s.push(q.top()->right);
                    tmp.push_back(q.top()->val);
                }
                q.pop();
            }

            if(tmp.size())
                res.push_back(tmp);
            tmp.clear();

            while(!s.empty())
            {
                if(s.top() != nullptr)
                {
                    q.push(s.top()->right);
                    q.push(s.top()->left);
                    tmp.push_back(s.top()->val);
                }
                s.pop();
            }
            if(tmp.size())
                res.push_back(tmp);
        }

        return res;
    }
};
// @lc code=end

