/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    unordered_map<int, int> map;

    void visit(TreeNode* root)
    {
        if(root == nullptr)
            return ;
        map[root->val]++;
        visit(root->left);
        visit(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        visit(root);
        
        int maxnum = 0;
        for(auto e:map)
        {
            if(e.second >= maxnum)
            {
                if(e.second > maxnum)
                    res.clear();
                res.push_back(e.first);
                maxnum = e.second;
            }
        }

        return res;
    }
};
// @lc code=end

