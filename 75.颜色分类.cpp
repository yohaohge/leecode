/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        int i=0;
        while(i <= right)
        {
            if(nums[i] == 0)
            {
                cout << nums[i] << nums[left] << endl;
                swap(nums[i], nums[left]);
                left++; 
                if(left > i) i++;
            }else if(nums[i] == 2)
            {
                cout << nums[i] << nums[right] << endl;
                swap(nums[i], nums[right]);
                right--;
            }
            else
            {
                i++;
            }
            
        }
        
    }
};
// @lc code=end

