/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/ 2;
            if(nums[mid] >= nums[left] && nums[mid] >= nums[right])
            {
                int prev = mid == 0 ? INT_MIN : nums[mid - 1];
                int next = mid == nums.size() -1 ? INT_MIN : nums[mid + 1];
                if(prev <= nums[mid] && nums[mid] >= next)
                    return mid;
                else if(next >= nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if(nums[left] > nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return -1;
    }
};
// @lc code=end

