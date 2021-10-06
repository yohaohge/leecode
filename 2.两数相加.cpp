/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode *p = &head;
        int num = 0;
        while(l1 || l2)
        {
            int val = num + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            p->next = new ListNode(val%10);
            p = p->next;
            num = val / 10;
            l1 ? l1 = l1->next : 0;
            l2 ? l2 = l2->next : 0;
        }

        if(num)
        {
            int val = num;
            p->next = new ListNode(val%10);
            p = p->next;
        }

        return head.next;
    }
};
// @lc code=end

