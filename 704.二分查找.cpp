/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int iLeft = 0, iRight = nums.size() -1;
        int iMid = 0;
        while(iLeft <= iRight)
        {
            iMid = iLeft + (iRight - iLeft)/2;
            if(nums[iMid] == target)
            {
                return iMid;
            }
            else if(nums[iMid] < target)
            {
                iLeft = iMid + 1;
            }
            else if(nums[iMid] > target)
            {
                iRight = iMid -1;
            }
        }

        return -1;
    }
};
// @lc code=end

