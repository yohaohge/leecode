/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int sum = 1;
        for(int i = 0; i < digits.size(); i++)
        {
            sum += digits[i];
            digits[i] = sum%10;
            sum /= 10;
        }

        if(sum > 0)
            digits.push_back(sum);
        reverse(digits.begin(), digits.end());

        return digits;
    }
};
// @lc code=end

