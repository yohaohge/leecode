/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        // ListNode node1;
        // ListNode node2;
        // ListNode *p1 = &node1;
        // ListNode *p2 = &node2;
        // while(head)
        // {
        //     if(head->val >= x)
        //     {
        //         p2->next = head;
        //         p2 = p2->next;
        //     }
        //     else
        //     {
        //         p1->next = head;
        //         p1 = p1->next;
        //     }
        //     head = head->next;
        // }
        // p2->next = nullptr;
        // p1->next = node2.next;
        // return node1.next; 

        ListNode node1;
        ListNode node2;
        ListNode *pEnd1 = &node1;
        ListNode *pEnd2 = &node2;

        while(head != nullptr)
        {
            if(head->val < x)
            {
                pEnd1->next = head;
                head = head->next;
                pEnd1 = pEnd1->next;
                pEnd1->next = nullptr;
            }
            else{
                pEnd2->next = head;
                head = head->next;
                pEnd2 = pEnd2->next;
                pEnd2->next =nullptr;
            }
        }

        pEnd1->next = node2.next;
        return node1.next;
    }
};
// @lc code=end

