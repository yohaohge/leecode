/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int left = 0, right = nums.size() - 1;

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] == 0)
        //     {
        //         swap(nums[i], nums[left]);
        //         left++;
        //     }

            
        // }


        // for(int i = nums.size() - 1; i >= 0; i--)
        // {
        //     if(nums[i] == 2)
        //     {
        //         swap(nums[i], nums[right]);
        //         right--;
        //     }
        // }
        
        int left = 0, index = 0, right = nums.size() - 1;

        while(index <= right)
        {
            if(nums[index] == 1)
                index++;
            else if(nums[index] == 0)
                // left不会出现等于2的情况，因为之前扫描过了，所以可以直接++
                swap(nums[index++], nums[left++]);
            else if(nums[index] == 2)
                swap(nums[index], nums[right--]);
        }
    }
};
// @lc code=end

