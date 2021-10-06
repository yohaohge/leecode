/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";
        
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize2(string data, int& len) {

        if(data.length() == 0)
            return nullptr;
        if(data[0] == '#')
        {
            len = 1;
            return nullptr;
        }
        
        int i = 0;
        for(i = 0; i < data.length(); i++)
        {
            if(data[i] == ',')
                break;
        }

        string datastr = data.substr(0, i);
        TreeNode* node = new TreeNode(atoi(datastr.c_str()));

        int leftlen = 0;
        node->left = deserialize2(data.substr(datastr.length() + 1), leftlen);
        int rightlen = 0;
        node->right = deserialize2(data.substr(datastr.length() + 1 + leftlen + 1), rightlen);
        len = datastr.length() + 1 + leftlen + 1 + rightlen;
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = 0;
        return deserialize2(data, len);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

