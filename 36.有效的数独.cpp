/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> column(9, vector<int>(10,0));
        vector<vector<int>> mix(9, vector<int>(10,0));

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    row[i][num] ++ ;
                    column[j][num] ++;
                    int k = i / 3 + (j / 3 * 3);
                    mix[k][num] ++; 
                    if(row[i][num] > 1 || column[j][num] > 1 || mix[k][num] > 1)
                        return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end

