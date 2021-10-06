/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, Node*> map;
public:

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        if (map.find(node->val) != map.end())
            return map[node->val];
        
        Node* pNode = new Node(node->val);
        map[node->val] = pNode;
        
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            Node* child = cloneGraph(node->neighbors[i]);
            pNode->neighbors.push_back(child);
        }

        return pNode;
    }
};
// @lc code=end

