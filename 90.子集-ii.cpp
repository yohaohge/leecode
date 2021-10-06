/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int index, string curstr, unordered_set<string>& set)
    {
        if(index >= nums.size())
        {
            if(set.find(curstr) == set.end())
            {
                res.push_back(cur);
                set.insert(curstr);
            }
            return;
        }

        dfs(res, nums, cur, index + 1, curstr, set);
        cur.push_back(nums[index]);
        dfs(res, nums, cur, index + 1, curstr + "," + to_string(nums[index]), set);
        cur.pop_back();

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<string> set;
        dfs(res, nums, cur, 0, "", set);

        return res;
    }
};
// @lc code=end

