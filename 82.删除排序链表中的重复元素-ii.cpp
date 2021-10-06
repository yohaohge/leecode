/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates2(ListNode* head, ListNode* last)
    {
        if(head == nullptr) return nullptr;

        if(last && last->val == head->val) 
            return  deleteDuplicates2(head->next, head);
        if(head->next != nullptr && head->next->val == head->val) 
            return deleteDuplicates2(head->next, head);

        head->next = deleteDuplicates2(head->next, head);
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        // return  deleteDuplicates2(head, nullptr);
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
                if(pSlow->next == pFast)
                {
                    pEnd->next = pSlow;
                    pEnd = pEnd->next;
                    pEnd->next = nullptr;
                }
                pSlow = pFast;
            }
        }

        if(pSlow && pSlow->next == nullptr)
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

