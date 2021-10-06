/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        // if(head == nullptr) return nullptr;

        // if(head->next != nullptr && head->next->val == head->val) 
        //     return deleteDuplicates(head->next);

        // head->next = deleteDuplicates(head->next);
        // return head;


        if(head == nullptr)
            return nullptr;
        ListNode node;
        node.next = head;

        ListNode *pEnd = &node;
        ListNode *pSlow = head;
        ListNode *pFast = head;

        while(pFast != nullptr)
        {
            if(pSlow->val == pFast->val)
            {
                pFast = pFast->next;
            }
            else
            {
                pEnd->next = pSlow;
                pEnd = pEnd->next;
                pEnd->next = nullptr;
                pSlow = pFast;
            }
        }

        if(pSlow)
        {
            pEnd->next = pSlow;
            pEnd = pEnd->next;
            pEnd->next = nullptr;
        }

        pEnd->next = nullptr;

        return node.next;
    }
};
// @lc code=end

