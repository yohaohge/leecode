/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int front = 0, back = 0;

        while(front < nums.size())
        {
            if(nums[front] == nums[back])
            {
                front++;
            }
            else
            {
                // 先加后赋值
                nums[++back] = nums[front++];
            }
        }

        return back + 1;
    }
};
// @lc code=end

