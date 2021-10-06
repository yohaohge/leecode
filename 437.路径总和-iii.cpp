/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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

    void pathSum2(TreeNode* root, int targetSum, vector<int>& presum, int& res) {
        if(root == nullptr)
            return;

        int sum = root->val;
        if(presum.size())
            sum += presum.back();
        presum.push_back(sum);

        if(sum == targetSum)
            res++;
        for(int i = 0; i < presum.size() - 1 ; i++)
        {
            if(sum - presum[i] == targetSum)
                res++;
        }

        pathSum2(root->left, targetSum, presum, res);
        pathSum2(root->right, targetSum, presum, res);

        presum.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        vector<int> presum;
        pathSum2(root, targetSum, presum, res);

        return res;
    }
};
// @lc code=end

