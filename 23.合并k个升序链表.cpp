/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

    // 可以递归实现
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //链表的归并排序中的归并
        for(int i = 0; i < (int)(lists.size())-1; i+=2)
        {
            ListNode* merge = mergeTwoLists(lists[i],lists[i+1]);
            lists.push_back(merge);
        }

        if(lists.size()) return lists.back();
        return nullptr;
    }
};
// @lc code=end

