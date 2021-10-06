/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */


// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        //  [) 和右边的值比较
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right])
                // mid一定不是最小值
                left = mid + 1;
            else if(nums[mid] < nums[right])
                right = mid; // mid可能是最小值
            else 
                right--;
        }

        return nums[left];
    }
};
// @lc code=end

