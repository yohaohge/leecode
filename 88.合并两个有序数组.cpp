/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int index3 = m + n - 1;

        while(index1 >= 0 && index2 >= 0)
        {
            nums1[index3--] = nums1[index1] > nums2[index2] ? nums1[index1--] : nums2[index2--];
        }

        while(index2 >= 0)
            nums1[index3--] = nums2[index2--];
        
    }
};
// @lc code=end

