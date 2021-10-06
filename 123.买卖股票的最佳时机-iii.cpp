/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3,vector<int>(2, 0)));
        for(int i = 0; i < prices.size(); i++)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
            for(int j = 2; j >= 1; j--)
            {
                // base case
                if(i - 1 == -1){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                }
                else
                {
                    // dp[i-1][j-1][1]  dp[i-1][j][1]  dp[i-1][j][0] dp[i-1][j-1][0]
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);

                    // dp[i-1][j-1][1]  dp[i-1][j][1]  dp[i-1][j][0] dp[i-1][j-1][0]
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                }
                          
            }
        }

        return dp[prices.size()-1][2][0];
    }
};
// @lc code=end

