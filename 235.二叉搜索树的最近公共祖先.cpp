/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    TreeNode* lca(TreeNode* root, TreeNode*p, TreeNode* q, int& cnt)
    {
        if(root == nullptr)
            return nullptr;
        
        int leftcnt = 0;
        int rightcnt = 0;
        TreeNode* left = lca(root->left, p, q, leftcnt);
        if(leftcnt == 2)
        {
            cnt = 2;
            return left;
        }
        TreeNode* right = lca(root->right, p, q, rightcnt);
        
        if(rightcnt == 2)
        {
            cnt = 2;
            return right;
        }

        if(leftcnt == 1 && rightcnt == 1)
        {
            cnt = 2;
            return root;
        }

        if(root == p || root == q) {
            cnt = leftcnt + rightcnt + 1;
            return root;
        }

        cnt = leftcnt + rightcnt;

        if(leftcnt > 0) return left;
        if(rightcnt > 0) return right;

        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // int cnt = 0;
        // TreeNode* target = lca(root, p, q, cnt);
        // if(cnt == 2)
        //     return target;
        // return nullptr;

        if(root == nullptr)
            return nullptr;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};
// @lc code=end

