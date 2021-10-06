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
    void reorderList(ListNode* head) {
        vector<ListNode*> stack; 
        ListNode* p = head;
        while (p != nullptr)
        {
            stack.push_back(p);
        }

        p = head;
        int index = stack.size() - 1;

        ListNode node;
        p = &node;
        for(int i = 0 ; i <= index; i++, index--)
        {
            p->next = head;
            p = p->next;
            head = head->next;
            if(i != index)
            {
                p->next = stack[index];
                p = p->next;
            }
        }


        
    }
};
// @lc code=end

