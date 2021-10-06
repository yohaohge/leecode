/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<int> tmp;
        if(rowIndex == 0)
        {
            ans.push_back(1);
            return ans;
        }

        while(rowIndex --)
        {
            tmp.push_back(1); // 头
            for(int i = 1; i < ans.size(); i++)
            {
                tmp.push_back(ans[i] + ans[i-1]);
            }
            tmp.push_back(1); // 尾
            ans = tmp;
            tmp.clear();
        }
        return ans;
    }
};
// @lc code=end

