/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void check(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int target, int sum)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(target == sum + root->val)
            {
                cur.push_back(root->val);
                res.push_back(cur);
                cur.pop_back();
            }
            return;
        }

        cur.push_back(root->val);
        check(res, cur, root->left, target, sum + root->val);
        check(res, cur, root->right, target, sum + root->val);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;

        check(res, cur, root, targetSum, 0);
        return res;
    }
};
// @lc code=end

