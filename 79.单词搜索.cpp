/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    struct point{
        int x;
        int y;
    };

    bool dfs(const vector<vector<char>>& board, const string word, string curstr, point curpoint, unordered_set<string>& visited, int index)
    {
        if(word == curstr) return true;

        if(curstr.length() > word.length()) return false;
        int m = board.size();
        int n = board[0].size();
        
        int x = curpoint.x;
        int y = curpoint.y;

        if(curpoint.x < 0 || curpoint.y < 0 || curpoint.x >= m || curpoint.y >= n )
        {
            return false;
        }
        if(visited.find(to_string(x)+","+to_string(y)) != visited.end())
        {
            return false;
        }

        if(word.length() > index && word[index] != board[x][y]) return false;
        curstr = curstr + board[x][y];
        visited.insert(to_string(x)+","+to_string(y));
        int res = dfs(board, word, curstr, {x+1,y}, visited,index+1);
        if(res)  return true;
        res = dfs(board, word, curstr, {x-1,y}, visited,index+1);
        if(res)  return true;
        res = dfs(board, word, curstr, {x,y-1}, visited,index+1);
        if(res)  return true;
        res = dfs(board, word, curstr, {x,y+1}, visited,index+1);
        if(res)  return true;
        visited.erase(to_string(x)+","+to_string(y));

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                unordered_set<string> visited;
                if( dfs(board, word, "", {i,j}, visited,0))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

