/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int back = 0, front = 0;
        int cnt = 0;
        while(front < nums.size())
        {
            if(nums[front] == val)
            {
                front++;
                cnt++;
            }
            else
            {
                // 先赋值后加
                nums[back++] = nums[front++];
            }
        }

        return nums.size() - cnt;
    }
};
// @lc code=end

