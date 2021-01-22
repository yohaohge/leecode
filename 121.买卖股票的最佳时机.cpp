/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        for(int i = 0; i < prices.size(); i++)
        {
            // base case
            if(i - 1 == -1){
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }

            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }

        return dp[prices.size()-1][0];
    }
};
// @lc code=end

