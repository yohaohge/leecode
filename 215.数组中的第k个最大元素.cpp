/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;

        for(int i = 0; i < nums.size(); i++)
        {
            if(q.size() < k)
                q.push(nums[i]);
            else if(nums[i] > q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        } 

        return q.top();
    }
};
// @lc code=end

