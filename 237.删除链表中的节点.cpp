/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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

// 当前值换成下一个值， 下一个节点被删掉
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node && node->next)
        {
            auto next = node->next;
            node->val = next->val;
            if(next->next == nullptr)
                node->next = nullptr;
            node = node->next;
        }
    }
};
// @lc code=end

