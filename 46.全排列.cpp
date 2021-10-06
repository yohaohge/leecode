/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    void recursion(vector<int> nums, int i,  vector<vector<int> > &res) {
        if (i == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++) {
            swap(nums[i], nums[k]);
            recursion(nums, i+1,  res);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        recursion(nums, 0, res);
        return res;
    }
};
// @lc code=end

