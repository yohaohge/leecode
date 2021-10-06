/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    ListNode* reverse(ListNode*head, ListNode* end)
    {
       ListNode *per = nullptr, *cur = head, *next;
        while(cur != end)
        {
            next = cur->next;
            cur->next = per;
            per = cur;
            cur = next;
        }

        return per;
        
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        if(slow == nullptr) return true;
        
        ListNode* p = reverse(head, slow);
        ListNode* p1 = p;
        ListNode* p2 = slow;
        if(fast) p2 = p2->next;
        bool res = true;
        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1->val != p2->val)
            {
                res = false; break;
            }
            p1 = p1->next; p2 = p2->next;
        }

        reverse(p, nullptr);
        if(p)
            p->next = slow;
        return res;
    }
};
// @lc code=end

