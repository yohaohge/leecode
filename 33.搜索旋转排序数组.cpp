/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            // 左边有序
            else if(nums[mid] >= nums[left])
            {
                if(nums[left] <= target && nums[mid] >= target)
                    right = mid - 1;
                else 
                    left = mid + 1;
            }
            else
            {
                if(nums[mid] <= target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end

