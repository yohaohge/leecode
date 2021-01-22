/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        auto tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
    ListNode* addTowNumbers2(ListNode* l1, ListNode* l2, int add)
    {
        if(l1 == nullptr && l2 == nullptr && add == 0) return nullptr; 
        

        int sum = 0;
        sum += l1?l1->val:0;
        sum += l2?l2->val:0;
        sum += add;

        auto p = new ListNode(sum%10);
        p->next = addTowNumbers2(l1?l1->next:nullptr, l2?l2->next:nullptr, sum/10);
        return p;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        auto sum = addTowNumbers2(l1,l2,0);
        sum = reverseList(sum);
        reverseList(l1);
        reverseList(l2);

        return sum;

    }
};
// @lc code=end

