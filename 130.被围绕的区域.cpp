/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void bfs(int x, int y, vector<vector<char>>& board, unordered_set<string>& allvisited)
    {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        q.push(pair<int, int>(x, y));
        bool change = true;
        vector<pair<int, int>> curvisited;
        while(q.size())
        {
            auto cur = q.front();
            string key = to_string(cur.first) + "#" + to_string(cur.second);
            if(allvisited.find(key) != allvisited.end())
            {
                q.pop();
                continue;
            }

            if(cur.first == 0 || cur.first == m - 1 || cur.second == 0 || cur.second == n - 1)
            {
                change = false;
            }

            vector<vector<int>> nextmove = {{1,0},{-1,0},{0, 1},{0, -1}};
            for(auto move:nextmove)
            {
                int nextX = cur.first + move[0];
                int nextY = cur.second+ move[1];
                if(nextX >= 0 && nextX <= m - 1 && nextY >= 0 && nextY <= n - 1 &&  board[nextX][nextY]  == 'O')
                {
                    q.push(pair<int, int>(nextX, nextY));
                }
            }
  
          
            allvisited.insert(key);
            curvisited.push_back(cur);
            q.pop();
        }

        if(change)
        {
            for(auto e:curvisited)
            {
                board[e.first][e.second] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0)  return;
        int n = board[0].size();

        unordered_set<string> visited;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[i][j] == 'O' && visited.find(to_string(i) + "#" + to_string(j)) == visited.end())
                {
                    bfs(i, j, board, visited);
                }
            }
        }
    }
};
// @lc code=end

