/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& res, int index, int n, int k, vector<int>& cur)
    {
        if(cur.size() == k)
        {
            res.push_back(cur);
            return;
        }

        if(n - index + 1 < k - cur.size())
            return;

        if(index > n)
            return;

        cur.push_back(index);
        dfs(res, index + 1, n, k, cur);
        cur.pop_back();
        dfs(res, index + 1, n, k, cur);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, 1, n, k, cur);

        return res;
    }
};
// @lc code=end

