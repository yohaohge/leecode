/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<string>>& res, string cur, string target, vector<string>& path,  unordered_map<string, unordered_set<string>>& child)
    {
        path.push_back(cur);
        if(cur == target)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }

        for(auto word:child[cur])
        {
            dfs(res, word, target, path, child);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> child;
        vector<vector<string>> res;
        queue<string> q;
        q.push(beginWord);
        set.erase(beginWord);
        int iFind = 0;
        while(q.size())
        {
            int len = q.size();
            vector<string> needrm;

            while(len --)
            {
                string cur = q.front();
                if(cur == endWord)
                {
                    vector<string> path;
                    dfs(res, beginWord, endWord, path, child);
                    return res;
                }

                for(int i = 0; i < q.front().length(); ++i)
                {
                    cur = q.front();
                    for(int j = 0; j < 26; ++j)
                    {
                        cur[i] = 'a' + j;

                        if(set.find(cur) != set.end() && cur != q.front())
                        {
                            child[q.front()].insert(cur);  
                            q.push(cur);
                            needrm.push_back(cur);
                        }
                    }
                }

                q.pop();
            }

            for(auto word:needrm)
                set.erase(word);
        }

        return res;
    }
};
// @lc code=end

