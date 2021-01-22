/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob2(vector<int>& nums, int start, int end)
    {
        if(start > end) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2,0));
        for(int i = start; i <= end; i++)
        {
            if(i == start)
            {
                dp[i][0] = 0;
                dp[i][1] = nums[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] =  dp[i-1][0] + nums[i];
        }
        return max(dp[end][0], dp[end][1]);

    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        
        return max(rob2(nums,2, nums.size()-2) + nums[0] , rob2(nums,1, nums.size() - 1));
    }
};
// @lc code=end

