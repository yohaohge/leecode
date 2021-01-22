/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST2(ListNode* head, int len)
    {
        if(head == nullptr||len == 0) return nullptr;
        int k = (len)/2 + 1;

        ListNode* p = head;
        for(int i = 0; i < k-1; i++)
        {
            p = p->next;
        }

        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBST2(head, k-1);
        root->right = sortedListToBST2(p->next, len-k);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;

        int len = 1;
        ListNode* p = head;
        while(p->next != nullptr) 
        {
            len++; p = p->next;
        }

        return sortedListToBST2(head, len);
    }
};
// @lc code=end

