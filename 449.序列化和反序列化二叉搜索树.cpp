/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
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
    void serialize(TreeNode* root, ostringstream& out)
    {
        if(root == nullptr)
        {
            out << "#";
            return;
        }

        out << to_string(root->val) << " " ;
        serialize(root->left, out);
        out << " ";
        serialize(root->right, out);

    }
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(istringstream& in)
    {
        string str;
        in >> str;
        if(str == "#")
            return nullptr;
        
        TreeNode* node = new TreeNode(atoi(str.c_str()));
        node->left = deserialize(in);
        node->right = deserialize(in);

        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

