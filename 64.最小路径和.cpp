/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        vector< vector<int> > dp(m, vector<int>(n,0));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) continue;
                if(i > 0 && j == 0) 
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                    continue;
                }
                if(j > 0 && i == 0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    continue;
                }

                dp[i][j] = grid[i][j] + min(dp[i-1][j] ,dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];    
    }
};
// @lc code=end

