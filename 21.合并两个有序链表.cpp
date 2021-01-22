/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
};
// @lc code=end

