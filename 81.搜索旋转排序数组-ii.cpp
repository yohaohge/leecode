/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left);
            if(nums[mid] == target)
                return true;
            // zuo边有序
            else if(nums[mid] >= nums[left] && nums[mid] != nums[right])
            {
                if(nums[mid] >= target && nums[left] <= target)
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

        return false;
    }
};
// @lc code=end

