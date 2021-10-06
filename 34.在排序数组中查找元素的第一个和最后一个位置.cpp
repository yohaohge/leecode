/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:

    int left_bound(vector<int>& nums, int target)
    {
        int iLeft = 0, iRight = nums.size() - 1;
        
        int iMid = 0;
        while(iLeft <= iRight)
        {
            iMid = iLeft + (iRight - iLeft)/2;
            if(nums[iMid] == target)
            {
                iRight = iMid - 1; // 如果这个位置是边界，最终iRight 不会再改变，iLeft会变成iRight+1
            }
            else if(nums[iMid] < target)
            {
                iLeft = iMid + 1;   
            }
            else if(nums[iMid] > target)
            {
                iRight = iMid - 1;
            }
        }

        // 条件
        if(iLeft >= nums.size()) return -1;
        return nums[iLeft] == target ? iLeft : -1; 
    }

    int right_bound(vector<int>& nums, int target)
    {
        int iLeft = 0, iRight = nums.size() -1;
        
        int iMid = 0;
        while(iLeft <= iRight)
        {
            iMid = iLeft + (iRight - iLeft)/2;
            if(nums[iMid] == target)
            {
                iLeft = iMid + 1;
            }
            else if(nums[iMid] < target)
            {
                iLeft = iMid + 1;   
            }
            else if(nums[iMid] > target)
            {
                iRight = iMid - 1;
            }
        }

        // 条件
        // if(iLeft == 0) return -1;
        // return nums[iLeft-1] == target ? iLeft-1 : -1; 

        if(iRight < 0) return -1;
        return nums[iRight] == target ? iRight : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        res.push_back(left_bound(nums, target));
        res.push_back(right_bound(nums, target));

        return res;
    }
};
// @lc code=end

