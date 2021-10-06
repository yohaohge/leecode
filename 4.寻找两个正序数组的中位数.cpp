/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findKth(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k)
    {
        int len1 = nums1.size() - start1;
        int len2 = nums2.size() - start2;
        cout  << "k = " << k << "len1 = " << len1 << "len2 = " << len2 <<  "start1 = " << start1 << "start2 = " << start2 << endl;
        if(len1 > len2)
        {
            return findKth(nums2, nums1, start2, start1, k);
        }

        if(len1 == 0)
            return nums2[start2 + k - 1];
        if(k == 1)
            return min(nums1[start1], nums2[start2]);
        
        int m = k/2;
        if(m > len1)
            m = len1;
        int n = k - m;

        if(nums1[start1 + m -1] < nums2[start2 + n -1])
            return findKth(nums1, nums2, start1 + m, start2, k - m);
        else
            return findKth(nums1, nums2, start1, start2 + n, k - n);

    }
    double findKthNumSortedArrays(vector<int>& nums1, vector<int>& nums2, int k)
    {
        if(nums1.size() > nums2.size()) return findKthNumSortedArrays(nums2, nums1, k);

        int left = 0, right = nums1.size();

        while(left <= right)
        {
            int mid1 = left + (right - left)/2;
            int mid2 = k - mid1;

            if(mid2 > nums2.size())
            {
                left = mid1 + 1;
                continue;
            }

            if(mid1 > k)
            {
                right = mid1 - 1;
                continue;
            }

            int leftNum1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int leftNum2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int rightNum1 = (mid1 == nums1.size()) ? INT_MAX : nums1[mid1];
            int rightNum2 = (mid2 == nums2.size()) ? INT_MAX : nums2[mid2];

            if(leftNum1 > rightNum2)
                right = mid1 - 1;
            else if(leftNum2 > rightNum1)
                left = mid1 + 1;
            else
                return max(leftNum1, leftNum2);
        }

        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size() + nums2.size() ;
        if(m%2 == 0)
        {
            return (findKth(nums1, nums2, 0, 0, m/2) + 
            findKth(nums1, nums2, 0, 0, m/2+1)) / 2.0;
        }
        else
        {
            return findKth(nums1, nums2, 0, 0,  m/2+1);
        }
        
    }
};
// @lc code=end

