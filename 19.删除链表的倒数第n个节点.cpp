/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        int i = 0;
        while (fast != nullptr && i < n+1)
        {
            fast = fast->next; i++;
        }
        
        if(i == n && fast == nullptr) return head->next;
        if(i == n+1 && fast == nullptr)  { head->next = head->next->next;}

        if(fast == nullptr) return head;

        while(fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return head;

    }
};