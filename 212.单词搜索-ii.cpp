/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
public:
    unordered_set<string> visited;
    bool dfs(vector<string>& res, vector<vector<char>>& board, string& word, int index, int x, int y)
    {
        if(index == word.length())
        {
            res.push_back(word);
            return true;
        }

        string pos = to_string(x) + "," + to_string(y);

        if(visited.find(pos) != visited.end())
            return false;
        visited.insert(pos);
        int m = board.size();
        int n = board[0].size();
        bool ret = false;
        if(x >= 0 && x < m && y >= 0 && y < n)
        {
            if(board[x][y] == word[index])
            {
                ret = dfs(res, board, word, index + 1, x + 1, y) ||
                   dfs(res, board, word, index + 1, x - 1, y) ||
                   dfs(res, board, word, index + 1, x, y + 1) ||
                   dfs(res, board, word, index + 1, x, y - 1);
            }
        }
        visited.erase(pos);

        return ret;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;

        int m = board.size();
        int n = board[0].size();
        unordered_map<char, int> chMap;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                chMap[board[i][j]]++;
            }
        }

        for(auto word: words)
        {
            bool check = false;
            for(int i = 0; i < word.length(); i++)
            {
                if(chMap[word[i]] == 0)
                {
                    check = true;
                    break;
                }
            }

            if(check)
                continue;
            
            for(int i = 0; i < m; i++)
            {
                bool find = false;
                for(int j = 0; j < n; j++)
                {
                    find = dfs(res, board, word, 0, i, j);
                    if(find) break;
                }
                if(find) break;
            }

        }
        

        return res;
    }

};
// @lc code=end

