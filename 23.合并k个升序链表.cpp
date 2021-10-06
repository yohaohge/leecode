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

 
struct cmp1
{
    bool operator()(const ListNode& node1, const ListNode& node2)
    {
        return node2.val < node1.val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode *p = &head;
        priority_queue<ListNode, vector<ListNode>, cmp1> q;

        for(auto e:lists)
        {
            if(e != nullptr)
            {
                ListNode node;
                node.next = e;
                node.val = e->val;
                q.push(node);
            }
        }

        while(!q.empty())
        {
            p->next = q.top().next;
            p = p->next;
            ListNode tmp = q.top();
            q.pop();
            if(tmp.next != nullptr && tmp.next->next != nullptr)
            {
                tmp.next = tmp.next->next;
                tmp.val = tmp.next->val;
                q.push(tmp);
            }

        }

        return head.next;

        // priority_queue<ListNode, vector<ListNode>, cmp1> q;
        // for(auto e: lists)
        // {
        //     if(e != nullptr)
        //         q.push(ListNode(e->val, e));
        // }

        // ListNode head;
        // ListNode* p;
        // p = &head;

        // while(!q.empty())
        // {
        //    ListNode node = q.top();
        //    q.pop();

        //    p->next = node.next;
        //    node.next = node.next->next;
        //    p = p->next;
        //    p->next = nullptr;
        //    if(node.next)
        //    {
        //        node.val = node.next->val;
        //        q.push(node);
        //    }
        // }

        // return head.next;
    }
};
// @lc code=end

