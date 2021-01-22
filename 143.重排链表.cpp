/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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

    ListNode* reverseList(ListNode* head) {
        ListNode* per = nullptr;
        ListNode* cur = head;
        ListNode* next;

        while(cur != nullptr)
        {
            next = cur->next;
            cur->next = per;
            per = cur;
            cur = next;
        }

        return per;
    }
    void reorderList(ListNode* head) {
        if(head)return ;
        // 找中间位置
        ListNode* fast = head;
        ListNode* slow = head;

        head->next= nullptr;

        // while(fast && fast->next)
        // {
        //     slow = slow->next;
        //     fast = fast->next;
        //     if(fast) 
        //         fast = fast->next;

        // }
        // slow->next = nullptr;

        // fast = reverseList(slow->next);
        // slow->next = nullptr;
        // slow = head;

     
    }
};
// @lc code=end

