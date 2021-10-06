/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode* next;
        ListNode node;
        ListNode* p = &node;
        while(cur)
        {
            next = cur->next;
            cur->next = nullptr;

            p = &node;
            while(p)
            {
                if(p->next == nullptr )
                {
                    p->next = cur;
                    cur = next;
                    break;
                }
                else if(p->next->val > cur->val)
                {
                    cur->next = p->next;
                    p->next = cur;
                    cur = next;
                    break;
                }
                p = p->next;
            }
        }

        return node.next;
    }
};
// @lc code=end

