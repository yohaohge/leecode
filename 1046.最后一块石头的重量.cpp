/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start

// 2021 06 01 7min
// priority_queue的使用不是很熟悉

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 模拟的方式
        // time O(nlogn)
        // space O(n)
        priority_queue<int> queue;
        for(auto e: stones)
            queue.push(e);
        
        while(queue.size() >= 2)
        {
            int a = queue.top(); queue.pop();
            int b = queue.top(); queue.pop();

            if(a != b)
            {
                queue.push(a-b);
            }
        }

        if(queue.size() > 0) 
            return queue.top();

        return 0;
    }
};
// @lc code=end

