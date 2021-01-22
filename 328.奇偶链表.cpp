/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode node1;
        ListNode node2;
        ListNode* pEnd1 = &node1;
        ListNode* pEnd2 = &node2;
        
        int i = 0;
        while(head)
        {
            if(i%2==0)
            {
                pEnd1->next = head;
                pEnd1 = pEnd1->next;
            }
            else
            {
                pEnd2->next = head;
                pEnd2 = pEnd2->next;
            }
            head = head->next;
            i++;
        }

        pEnd1->next = node2.next;
        pEnd2->next = nullptr;
        return node1.next;
        
    }
};
// @lc code=end

