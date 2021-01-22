/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

    ListNode* reverse(ListNode* head, ListNode* end)
    {
        ListNode *per = nullptr, *cur = head, *next;
        while(cur != end)
        {
            next = cur->next;
            cur->next = per;
            per = cur;
            cur = next;
        }

        return per;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *end = head;
        for(int i = 0; i < k ;i++)
        {
            if(end == nullptr)
                return head;
            else 
                end = end->next;
        }

        auto p = reverse(head, end);
        head->next = reverseKGroup(end,k);
        return p;
    }
};
// @lc code=end

