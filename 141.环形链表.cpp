/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != nullptr)
        {
            fast=fast->next;
            slow=slow->next;
            if(fast != nullptr) fast = fast->next;
            if(fast == slow && slow != nullptr) return true;
        }
        return false;
    }
};
// @lc code=end

