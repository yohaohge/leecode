/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length() == 0) return word2.length();
        if(word2.length() == 0) return word1.length();

        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,INT_MAX));
        for(int i = 0; i <= word1.length(); i ++)
        {
            for(int j = 0; j <= word2.length(); j++)
            {
                if(i == 0) {
                    dp[i][j] = j;continue;
                }
                if(j == 0)
                {
                    dp[i][j] = i;continue;
                }

                dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
                dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
                dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j]);

            }
        }
        return dp[word1.length()][word2.length()];
    }
};
// @lc code=end

