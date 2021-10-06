/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
// 连成一个环，找环入口
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        auto p1 = headA;
        auto p2 = headB;

        while(p1)
        {
            p1 = p1->next; len1++;
        }

        while (p2)
        {
            p2 = p2->next; len2++;
        }

        p1 = headA;
        p2 = headB;
        int diff = len1 - len2;
        if(diff > 0)
        {
            while (diff--)
            {
                p1 = p1->next;
            }
        }
        else if(diff < 0)
        {
            diff = abs(diff);
            while (diff--)
            {
                p2 = p2->next;
            }
            
        }

        while(p1&&p2)
        {
            if(p1 == p2) return p1;
            p1 = p1->next;  p2 = p2->next;
        }
        
        return nullptr;
        
    }
};
// @lc code=end

