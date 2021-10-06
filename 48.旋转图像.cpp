/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 按圈旋转
        int n = matrix.size();

        for(int i = 0; i < n/2; i++ )
        {
            int start = i;
            int end =  n-i-1;
            for(int j = 0; j < n-2*i - 1; j++)
            {
                int x1 = i, y1 = i+j;
                int x2 = i+j, y2 = end;
                int x3 = end, y3 = end-j;
                int x4 = end-j , y4 = i ;

                int tmp = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = matrix[x1][y1];
                matrix[x1][y1] = tmp;
            }
        }
    }
};
// @lc code=end

