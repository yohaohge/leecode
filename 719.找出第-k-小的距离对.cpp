/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<int, vector<int>, less<int>> q;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(q.size() < k)
            {
                q.push(nums[i]- nums[i]);
            }
            else if(q.top() >nums[i]- nums[i])
            {
                q.pop();
                q.push(nums[i]- nums[i]);
                if(q.top() == 0)
                    return 0;
            }
        }

        return q.top();
    }
};
// @lc code=end

