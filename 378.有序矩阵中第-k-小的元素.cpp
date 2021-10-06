/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int checkNum(vector<vector<int>>& matrix, int num)
    {
        int m = matrix.size();
        if(m == 0) 
            return 0;
        int n = matrix[0].size();

        int x = m - 1, y = 0;

        int cnt = 0;

        while(x >= 0 && y <= n - 1)
        {
            if(matrix[x][y] > num)
            {
                //cnt += y;
                x--;
            }
            else if(y == n - 1 || matrix[x][y+1] > num)
            {
                cnt += y + 1;
                x--;
            }
            else
            {
                y++;
            }

        }

        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       
        int m = matrix.size();
        if(m == 0) 
            return 0;
        int n = matrix[0].size();

        int left = matrix[0][0], right = matrix[m-1][n-1];
        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(checkNum(matrix, mid) < k)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};
// @lc code=end

