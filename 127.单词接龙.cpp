/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
   
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        int iNum = 1;
        set.erase(beginWord);
        while(q.size())
        {
            int len = q.size();
            while(len --)
            {
                string cur = q.front();
                if(cur == endWord)
                {
                    return iNum;
                }

                for(int i = 0; i < q.front().length(); ++i)
                {
                    cur = q.front();
                    for(int j = 0; j < 26; ++j)
                    {
                        cur[i] = 'a' + j;
                        if(set.find(cur) != set.end())
                        {
                            q.push(cur);
                            set.erase(cur);
                        }
                    }
                }

                q.pop();
            }

            iNum++;
        }

        return 0;
    }
};
// @lc code=end

