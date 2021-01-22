/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
     ListNode* reverseList(ListNode* head, ListNode* end ) {
        if(head == end||head->next == end) return head;
        auto tmp = reverseList(head->next, end);
        head->next->next = head;
        head->next = end;
        return tmp;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1)
        {
            auto p = head;
            for(int i = 0; i < n; i++)
            {
                p = p->next ;
            }
            
            auto tmp = reverseList(head, p);
            return tmp;
        }

        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }
};
// @lc code=end

