/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode node;
        node.next = head;
        ListNode* per = &node;
        ListNode* cur = head;
        while(cur)
        {
            if(cur->val == val)
            {
                per->next = cur->next;
                cur = cur->next;
            }
            else{
                per = cur;
                cur = cur->next;
            }
        }

        return node.next;
    }
};
// @lc code=end

