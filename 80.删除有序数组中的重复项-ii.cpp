/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// 2021 06 01 有卡住

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int repeat = 0;
        for(int i = 1, index = 0; i < nums.size(); i++)
        {
            if(nums[index] != nums[i])
            {
                nums[index+1] = nums[i];
                index++;
                cnt = 1;
            }
            else
            {
                if(cnt < 2)
                {
                    nums[index+1] = nums[i];
                    index++;
                }
                else
                {
                    repeat++;
                }
                cnt++;
            }
        }

        return nums.size() - repeat;

    }
};
// @lc code=end

