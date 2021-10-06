/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    int visit(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int sum = root->val;
        sum += visit(root->left);
        sum += visit(root->right);
        map[sum] ++;
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        visit(root);

        vector<int> res;
        int maxcnt = 0;
        for(auto e:map)
        {
            if(e.second >= maxcnt)
            {
                if(e.second > maxcnt)
                    res.clear();
                res.push_back(e.first);
                maxcnt = e.second;
            }

        }

        return res;
    }   
};
// @lc code=end

