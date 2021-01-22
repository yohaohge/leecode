/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount+1, 1000000);
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i == coins[j])
                {
                    dp[i] = 1;
                }
                else if(i > coins[j])
                {
                   dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
                
            }
        }
        return dp[amount] == 1000000 ? -1 :  dp[amount] ;

    }
};
// @lc code=end

