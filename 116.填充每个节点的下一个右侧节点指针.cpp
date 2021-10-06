/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect2(Node* left, Node* right)
    {
        if(left == nullptr)
            return ;
        left->next = right;

        connect2(left->left, left->right);
        connect2(right->left, right->right);
        connect2(left->right, right->left);
    }

    Node* connect(Node* root) {
        if(root)
            connect2(root->left, root->right);
        return root;
    }
};
// @lc code=end

