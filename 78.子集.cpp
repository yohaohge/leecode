/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>>  res;
    void dfs(vector<int>& nums, vector<int>& current, int index)
    {
        if(index == nums.size())
        {
            res.push_back(current);
            return ;
        }
        dfs(nums, current, index+1);
        current.push_back(nums[index]);
        dfs(nums, current, index+1);
        current.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<int> current;
         dfs(nums, current, 0);

         return res;
    }
};
// @lc code=end

