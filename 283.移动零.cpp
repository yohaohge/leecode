/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int index = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                swap(nums[i], nums[index++]);
        }
       
    }
};
// @lc code=end

