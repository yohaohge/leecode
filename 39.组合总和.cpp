/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& res, vector<int>& candidates, int index, int sum, vector<int>& cur, int target)
    {

        cout << sum << endl;
        if(sum == target)
        {
            res.push_back(cur);
        }

        if(index >= candidates.size() || (sum >= target))
            return;
        for(int i = 0; true; i++)
        {
            if(i * candidates[index] + sum > target)
                break;
            for(int j = 0; j < i; j++)
                cur.push_back(candidates[index]);
            dfs(res, candidates, index + 1, sum + candidates[index] * i, cur, target);
            for(int j = 0; j < i; j++)
                cur.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, candidates, 0, 0, cur, target);
        
        return res;
    }
};
// @lc code=end

