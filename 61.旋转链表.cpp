/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode *end = head;
        ListNode *newEnd = head;
        int len = 0;
        while(end != nullptr)
        {
            len++;
            end = end->next;
        }
        end = head;
        k = k % len;
        if(k == 0)
            return head;
        
        for(int i = 0; i < k; i++)
            end = end->next;
        while(end->next)
        {
            newEnd = newEnd->next;
            end = end->next;
        }

        end->next = head;
        head = newEnd->next;
        newEnd->next = nullptr;
        return head;
        // if(head == nullptr||k==0) return head;

        // int len = 1;
        // ListNode *pEnd = head;
        // while (pEnd->next != nullptr)
        // {
        //     len++;
        //     pEnd = pEnd->next;
        // }

        // k = k % len;
        // if(k == 0) return head;

        // int m = len - k;

        // ListNode *cur = head;
        // ListNode *per = nullptr;
        // while(m--)
        // {
        //     per = cur;
        //     cur = cur->next;
        // }

        // pEnd->next = head;
        // per->next = nullptr;

        // return cur;
        
    }
};
// @lc code=end

