/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<string, int> map;

    int rob2(TreeNode* root, int flag, string key)
    {
        int ret =  0;
        string key1 = key + to_string(flag);
        if(map.find(key1) != map.end())
            return map[key1];
        if(root == NULL) ret = 0;
        else if(flag == 0)
            ret =  max(rob2(root->left, 0, key+"left"), rob2(root->left, 1,key+"left")) +  max(rob2(root->right, 0,key+"right"), rob2(root->right, 1,key+"right"));
        else
            ret = root->val + rob2(root->left, 0,key+"left") + rob2(root->right, 0, key+"right");
        map[key1] = ret;
        return ret;
    }
    int rob(TreeNode* root) {

        return max(rob2(root,0, "root"), rob2(root,1,"root") );
    }
};
// @lc code=end

