/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curMax = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(curMax < i) return false;
            if(curMax >= nums.size()-1) return true;
            curMax = max(curMax, nums[i]+i);
        }

        return false;
    }
};
// @lc code=end

