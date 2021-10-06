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
        if(head == nullptr || end == nullptr)
            return head;
        
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = head->next;

        while(cur != nullptr && prev != end)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            if(next)
                next = next->next;
        }

        return end;

        // ListNode *per = nullptr, *cur = head, *next;
        // while(cur != end)
        // {
        //     next = cur->next;
        //     cur->next = per;
        //     per = cur;
        //     cur = next;
        // }

        // return per;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 0 || k == 1)
            return head;
        // 非递归
        ListNode node;
        node.next = head;

        ListNode *beginPrev = &node;
        ListNode *begin, *end , *endNext;

        while(beginPrev)
        {   
            begin = beginPrev->next;
            end = begin;
            for(int i = 0; i < k - 1; i++)
            {
                if(end != nullptr)
                    end = end->next;
                else
                    break;
            }

            if(end == nullptr)
                break;
            endNext = end->next;

            reverse(begin, end);

            beginPrev->next = end;
            begin->next = endNext;

            beginPrev = begin;
        }
        return node.next;

        // ListNode *end = head;
        // for(int i = 0; i < k ;i++)
        // {
        //     if(end == nullptr)
        //         return head;
        //     else 
        //         end = end->next;
        // }

        // auto p = reverse(head, end);
        // head->next = reverseKGroup(end,k);
        // return p;
    }
};
// @lc code=end

