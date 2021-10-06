/*
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int findInMountainArray(int target, MountainArray &mountainArr) {
        // 查找峰值
        int left = 0, right = mountainArr.length() - 2;
        while(left <= right)
        {
            int mid = left + (right -left)/2;
            int midvalue = mountainArr.get(mid);
            int nextvalue = mountainArr.get(mid+1);
            if(midvalue < nextvalue)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1 ;
            }
        }

        int k = left;
        // 左边查找
        left = 0; right = k;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int midvalue = mountainArr.get(mid);
            if(midvalue == target)
            {
                return mid;
            }
            else if(midvalue < target)
            {
                left = mid + 1;
            }
            else if(midvalue > target)
            {
                right = mid - 1;
            }
            
        }

        // 左边没有找到 右边查找， 右边是递减区间
        left = k+1; right = mountainArr.length() - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int midvalue = mountainArr.get(mid);
            if(midvalue == target)
            {
                return mid;
            }
            else if(midvalue < target)
            {
                right = mid - 1;

            }
            else if(midvalue > target)
            {
                left = mid + 1;
            }
            
        }

        return -1;

    }
};
// @lc code=end

