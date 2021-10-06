/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
  if(nums.size() == 0) return 0;
        
        int lastTake = 0, lastNotTake = 0, curTake = 0, curNotTake = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            lastTake = curTake; lastNotTake = curNotTake;
            if(i == 0)
            {
                curNotTake = 0;
                curTake = nums[i];
                continue;
            }
            curNotTake = max(lastTake, lastNotTake);
            curTake = lastNotTake + nums[i];
        }

        return max(curTake, curNotTake);
    }
};
// @lc code=end

