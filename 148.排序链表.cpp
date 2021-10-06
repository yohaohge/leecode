/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode node;
        ListNode *pEnd = &node;

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val < l2->val)
            {
                pEnd->next = l1;
                l1 = l1->next;
            }
            else
            {
                pEnd->next = l2;
                l2 = l2->next;
            }
            pEnd = pEnd->next;
        }

        pEnd->next = l1 ? l1 : l2;

        return node.next;

    }
    ListNode* partition(ListNode* head, int len)
    {
        if(head == nullptr || len <= 1) return head;
        int k = len/2;
        auto pk = head;
        ListNode* per = nullptr;
        while (k--)
        {
            per = pk;
            pk = pk->next;
        }
        per->next = nullptr;
        auto pK = head;
        auto first = partition(head, len/2);
        auto second = partition(pk, len - len/2);
        return mergeTwoLists(first, second);

    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        int len = 1;
        auto p = head;
        while (p->next)
        {
            p = p->next; len++;
        }

        return partition(head, len);
        
    }
};
// @lc code=end

