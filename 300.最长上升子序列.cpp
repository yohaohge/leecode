/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ret = 1;
        vector<int>dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    ret = max(dp[i],ret);
                }

            }
        }

        return ret;
    }
};
// @lc code=end

