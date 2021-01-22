/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;


    void permute2(vector<int>& nums, int index) {
         if(index == nums.size()) {         
             res.push_back(nums);
             return;
         }

         for(int i = 0; i <= index; i++)
         {
             swap(nums[index],nums[i]);
             permute2(nums, index+1);
             swap(nums[index],nums[i]);
         }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        permute2(nums, 0);
        return res;
    }

};
// @lc code=end

