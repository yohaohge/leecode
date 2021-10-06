/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0)
            return res;
        int m = matrix.size(), n = matrix[0].size();
        int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;

        while(x1 <= x2 && y1 <= y2)
        {
            for(int i = y1; i <= y2; i++)
            {
                res.push_back(matrix[x1][i]);
            }

            for(int i = x1+1; i <= x2; i++)
            {
                res.push_back(matrix[i][y2]);
            }

            for(int i = y2-1; i >= y1; i--)
            {
                if(x1 == x2) break; // coner case
                res.push_back(matrix[x2][i]);
            }

            for(int i = x2-1; i > x1; i--)
            {
                if(y1 == y2) break; // coner case
                res.push_back(matrix[i][y1]);
            }

            x1++; y1++; x2--; y2--;
        }

        return res;
    }
};
// @lc code=end

