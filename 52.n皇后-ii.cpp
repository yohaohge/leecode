/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int cnt;

    bool checkCur(int x, int y, vector<string>& cur, int n)
    {
        int x1 = x - min(x,y);
        int y1 = y - min(x,y);
        
        // y == 0
        int x2 = x + min(n - x, n - y) - 1;
        int y2 = y - min(n - x, n - y) + 1;

        if(y2 < 0)
        {
            y2 = 0;
            x2 = x + y;
        }

        for(int i = 0; i < n; i++)
        {
            if(cur[x][i] != '.')
                return false;
            if(cur[i][y] != '.')
                return false;

            if(x1 + i <= n -1 && y1 +i <= n - 1 && cur[x1+i][y1+i] != '.')
                return false;
            if(x2 - i >= 0 && y2 + i <= n - 1 && cur[x2-i][y2+i] != '.')
                return false;
        }

        return true;
           
    }
    void dfs(vector<vector<string>>& res, int n, int x, vector<string>& cur)
    {
        if(x == n)
        {
            cnt ++;
            return;
        }
        for(int y = 0; y < n; y++)
        {
            if(checkCur(x, y, cur, n) == true)
            {
                cur[x][y] = 'Q';
                dfs(res, n, x + 1, cur);
                cur[x][y] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> cur(n, string(n, '.'));
        dfs(res, n, 0, cur);
        return cnt;
    }
};
// @lc code=end

