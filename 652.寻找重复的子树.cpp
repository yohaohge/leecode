/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    unordered_map<string, int> map;
    vector<TreeNode*> res;
    string visit(TreeNode* root)
    {
        if(root == nullptr)
            return "#";
        string left = visit(root->left);
        string right = visit(root->right);

        string str = to_string(root->val) + "," + left + "," + right;

        map[str] ++;
        if(map[str] == 2)
        {
            res.push_back(root);
        }

        return str;
    }    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        visit(root);
        return res;
    }
};
// @lc code=end

