/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int ans = 0;

        vector<vector<bool>> visited(m,vector<bool>(n,false));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 || i == m - 1 || j == 0 || j == n -1)
                {
                    q.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        while(q.size())
        {
            auto top = q.top();
            q.pop();
            int x = top.second.first;
            int y = top.second.second;
            int value = top.first;

            vector<vector<int>> movelist = {{1, 0}, {-1, 0},{0, -1}, {0, 1}};

            for(auto move:movelist)
            {
                int nextX = x + move[0];
                int nextY = y + move[1];

                if(nextX >=0 && nextX <= m - 1 && nextY >= 0 && nextY <= n - 1 && visited[nextX][nextY] == false)
                {
                    visited[nextX][nextY] = true;
                    ans += max(0, value - heightMap[nextX][nextY]);
                    q.push({max(value, heightMap[nextX][nextY]), {nextX, nextY}});
                }
            }
        }

        return ans;
    }
};
// @lc code=end

