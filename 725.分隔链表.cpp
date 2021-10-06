/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        auto p = root;
        while(p) { p = p->next; len++;}
        int m = len/k;
        int n = len%k;

        vector<ListNode*> res;
        p = root;
        ListNode* per = nullptr;
        for(int i = 0; i < k; i++)
        {
            res.push_back(p);
            int size = m;
            if(i < n)
            {
                size += 1;
            }
            while(size-- && p)
            {
                per = p;
                p = p->next;
            }

            if(per) per->next = nullptr;

        }

        return res;

    }
};
// @lc code=end

