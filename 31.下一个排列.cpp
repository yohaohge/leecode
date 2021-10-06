/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 1;
        for(i = nums.size() - 1; i >= 1; i--)
        {
            if(nums[i] > nums[i-1])
                break;
        }
        
        int j = nums.size() - 1;
        if(i > 0)
        {
            for(;j >= i; j--)
            {
                if(nums[j] > nums[i-1])
                    break;
            }
            swap(nums[j], nums[i-1]);
        }
        j = nums.size() - 1;
        while(i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    }
};
// @lc code=end

