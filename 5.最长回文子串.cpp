/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        string res;
        vector<int> dp(len, 0);
        for(int j = 0; j < len; j++)
        {
            for(int i = 0; i <= j; i++)
            {
                if(i == j) 
                {
                    dp[i] = 1;
                }
                else if(s[i] == s[j])
                {
                    if(i+1 < j-1)
                    {
                        dp[i] = dp[i+1];
                    }
                    else
                    {
                        dp[i] = 1;
                    }
                }
                else
                {
                    dp[i] = 0;
                }

                if(dp[i] == 1 && j - i + 1 > res.length())
                {
                    res = s.substr(i, j - i + 1);
                }
            }
        }

        return res;
    }
};
// @lc code=end

