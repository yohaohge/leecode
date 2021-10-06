/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    int xTable[9][9] = {0};
    int yTable[9][9] = {0};
    int otherTable[9][9] = {0};

    int otherIndex(int x, int y)
    {
        return (x/3*3 + y/3);
    }

    bool solveSudokuHelper(vector<vector<char>>& board, int i)
    {
        int x = i / 9;
        int y = i % 9;
        cout << x << "," << y << endl;
        if(x >= 9)
        {
            return true;
        }

        if(board[x][y] == '.')
        {
            bool find = false;
            int index = otherIndex(x, y);
            for(int j = 1; j <= 9; j++)
            {   
                char ch = '0' + j;
                if(xTable[x][ch-'1'] != 0)
                    continue;
                if(yTable[y][ch-'1'] != 0)
                    continue;
                if(otherTable[index][ch-'1'] != 0)
                    continue;
                
                xTable[x][ch-'1'] = 1;
                yTable[y][ch-'1'] = 1;
                otherTable[index][ch-'1'] = 1;

                board[x][y] = ch;
                find = solveSudokuHelper(board, i+1);
                if(!find)
                {
                    board[x][y] = '.';
                    xTable[x][ch-'1'] = 0;
                    yTable[y][ch-'1'] = 0;
                    otherTable[index][ch-'1'] = 0;
                }
                else 
                    return true;
            }
            return false;
        }
        else
        {
            return solveSudokuHelper(board, i+1);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if(ch == '.') continue;
                xTable[i][ch-'1'] = 1;
                yTable[j][ch-'1'] = 1;
                int index = otherIndex(i, j);
                otherTable[index][ch - '1'] = 1;
            }
        }
        solveSudokuHelper(board, 0);
    }
};
// @lc code=end

