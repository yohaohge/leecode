/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push(pair<int,int>(x,y));
        unordered_set<string> visited;
        while(q.size())
        {
            auto front = q.front();
            string key = to_string(front.first) + "#" + to_string(front.second);
            if(visited.find(key) != visited.end())
            {
                q.pop(); continue;
            }
            grid[front.first][front.second] = '0';
            visited.insert(key);
            vector<vector<int>> movelist = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            
            for(auto move:movelist)
            {
                int nextX = front.first + move[0];
                int nextY = front.second + move[1];

                if(nextX >= 0 && nextX <= m -1 && nextY >=0 && nextY <= n -1 && grid[nextX][nextY] == '1')
                {
                    q.push(pair<int, int>(nextX, nextY));
                }
            }

            q.pop();
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    ans ++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

