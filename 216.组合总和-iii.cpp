/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int index, int sum, int n, int k, int cnt)
    {  
        if(sum == n)
        {
            if(cnt == k)
                res.push_back(cur);
            return;
        }

        if(index == 10 || sum > n || cnt > k)
            return;
        dfs(res, cur, index + 1, sum, n, k, cnt);
        cur.push_back(index);
        dfs(res, cur, index + 1, sum + index, n, k, cnt + 1);
        cur.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, 1, 0, n, k, 0);
        return res;
    }
};
// @lc code=end

