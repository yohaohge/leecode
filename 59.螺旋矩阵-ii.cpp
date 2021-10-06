/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int iNum = 1;
        int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;

        while(x1 <= x2 && y1 <= y2)
        {
            for(int i = y1; i <= y2; i++)
            {
                matrix[x1][i] = iNum++;
            }

            for(int i = x1+1; i <= x2; i++)
            {
                matrix[i][y2] = iNum++;
            }

            for(int i = y2-1; i >= y1; i--)
            {
                matrix[x2][i] = iNum++;
            }

            for(int i = x2-1; i > x1; i--)
            {
                matrix[i][y1] = iNum++;
            }

            x1++; y1++; x2--; y2--;
        }

        return matrix;
    }
};
// @lc code=end

