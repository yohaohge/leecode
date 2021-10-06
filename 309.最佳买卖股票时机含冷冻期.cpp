/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        for(int i = 0; i < prices.size(); i++)
        {
            if(i == 0)
            {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }

            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] );
            if(i >= 2)
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            else
                dp[i][1] = max(dp[i-1][1], -prices[i]);
            
        }

        return dp[prices.size()-1][0];
    }
};
// @lc code=end

// 二分查找
// binarySeach(vector<int> nums, target)
// {
//     left = 0; right = nums.size() -1;
    
//     while(left <= right)
//     {
//         mid = left = (right -left)/2;
//         if(nums[mid] == target)
//         {
//             // 普通查找 直接返回 true
//             // 左边界  right = mid - 1
//             // 右边界  left = mid + 1
//         }
//         else if(num[mid] < target)
//         {
//              left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }

//     // 普通查找 直接返回false
//     // 左边界  判断 left位置是否为 target 是返回left 否返回 -1
//     // 右边界  返回 left -1 位置是否为 target 是返回left -1 否返回 -1
// }