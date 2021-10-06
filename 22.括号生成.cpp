/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>& res, int n, int left, int right, string cur)
    {
        if(right > left)
            return;
        if(left - right > n)
            return;
        // base case
        if(n == 0 )
        {
            if(left == right )res.push_back(cur);
            return;
        }
        
        dfs(res, n - 1, left + 1, right, cur + "(");

        if(right < left)
        {
            dfs(res, n - 1, left, right + 1, cur + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
            return res;
        dfs(res, n * 2, 0, 0, "");

        return res;
    }
};
// @lc code=end

