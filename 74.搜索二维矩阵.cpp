

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();

        int x = m - 1, y = 0;

        while(x >= 0 && y < n)
        {
            if(matrix[x][y] > target)
                x--;
            else if(matrix[x][y] < target)
                y++;
            else
                return true;
        }

        return false;
    
    }
};
// @lc code=end

