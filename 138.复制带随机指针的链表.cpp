/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        Node *src = head;
        Node node(0);
        Node* pNew = nullptr;
        while(src !=nullptr)
        {
            pNew = new Node(src->val);
            pNew->next = src->next;
            src->next = pNew;
            src = pNew->next;
        }

        src = head;
        while(src != nullptr)
        {
            pNew = src->next;
            pNew->random = src->random ? src->random->next : nullptr;
            src = pNew->next;
        }

        src = head;
        pNew = &node;
        node.next = pNew;
        while (src != nullptr)
        {
            pNew->next = src->next;
            pNew = pNew->next;
            src->next = pNew->next;
            src = src->next;
        }
        

        return node.next;
    }
};
// @lc code=end

