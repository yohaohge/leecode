/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // if(n == 0) return 1;
        // if(n == 1) return 1;

        // int sum = 0;
        // for(int i = 1; i <= n; i++)
        // {
        //     sum += numTrees(i-1) * numTrees(n-i);
        // }

        vector<int> dp(n+1,1);
       
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 0; j < i; j++ )
            {
                sum += dp[j] * dp[i-j-1];
            }  
            dp[i] = sum; 
            cout << sum << endl;
        }


        return dp[n];
    }
};
// @lc code=end

