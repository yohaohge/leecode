/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:

    int maxProfitWithoutK(vector<int>& prices)
    {
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

            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    
        }

        return dp[prices.size()-1][0];

    }

    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0 || k <= 0) return 0;
        if(k > prices.size()/2) return maxProfitWithoutK(prices);

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k+1, vector<int>(2,0)));
        for(int i = 0; i < prices.size(); i++)
        {
            dp[i][0][1] = INT_MIN;
            dp[i][0][0] = 0;

            for(int j = k; j >= 1; j--)
            {
                if(i == 0)
                {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }

                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }

        return dp[prices.size()-1][k][0];

    }
};
// @lc code=end

