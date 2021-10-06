/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        for(int i = 0; i < triangle.size(); ++i)
        {
            for(int j = 0; j < triangle[i].size(); ++j)
            {
                if(i > 0)
                {
                    int iNum = INT_MAX;
                    if(j < i)
                    {
                        iNum = min(iNum, triangle[i-1][j]); 
                    }
                    if(j > 0)
                    {
                        iNum = min(iNum,triangle[i-1][j-1]);
                    }

                    triangle[i][j] += iNum;
                }
                if(i == triangle.size() - 1)
                    ans = min(triangle[i][j], ans);
            }
        }

        return ans;
    }
};
// @lc code=end

