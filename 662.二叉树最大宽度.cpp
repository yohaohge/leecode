/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        size_t  res = 0;
        queue<TreeNode*> q;
        queue<size_t > qIndex; 
        q.push(root);
        qIndex.push(1);
        while(q.size())
        {
            int len = q.size();
            size_t  first = 0;
            size_t  end = 0;
            while(len--)
            {
                if(q.front())
                {
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                    qIndex.push(qIndex.front() * 2 );
                    qIndex.push((qIndex.front() * 2 + 1));
                    if(first == 0) {
                        first = qIndex.front();
                        end = qIndex.front();
                    }
                    else
                        end = qIndex.front();
                }

                q.pop();
                qIndex.pop();
            }

            if(end > 0)
            {
                cout << res << endl;
                res = max(res, end - first + 1);
            }
        }

        return (int)res;
    }
};
// @lc code=end

