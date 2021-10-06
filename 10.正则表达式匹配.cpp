/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        // 递归
        // if (p.empty())
        // {
        //     return s.empty();
        // }
        // if ('*' == p[1])
        // {
        //     return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        // }
        // else
        // {
        //     return !s.empty() && (s[0] == p[0] || '.' == p[0]) && (isMatch(s.substr(1), p.substr(1)));
        // }

        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {  
                if(j == 0)
                {
                    dp[i][j] = i == 0 ? true : false;
                }
                else if(i == 0)
                {
                    dp[i][j] = (p[j-1] == '*') ? dp[i][j-2] : false;
                } 
                else if(s[i-1] == p[j-1] || p[j-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2] == s[i-1] || p[j-2] == '.')
                        dp[i][j] =  dp[i][j] || dp[i-1][j-2] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = false;
                }

            }

            cout << endl;
        }

        return dp[m][n];
    }
};
// @lc code=end

