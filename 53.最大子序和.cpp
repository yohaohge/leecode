/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxSum = INT_MIN;
        for(auto num:nums)
        {
            sum+=num;
            maxSum = max(sum, maxSum);
            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};
// @lc code=end

