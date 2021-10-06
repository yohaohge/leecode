/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int left = 0, right = citations.size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(citations[mid] >= citations.size() - mid)
                right = mid - 1;
            else
                left = mid + 1;

        }

        return citations.size() - left;
    }
};
// @lc code=end

