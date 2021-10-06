/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:


    vector<int> findSubstring(string s, vector<string>& words) {
        // 暴力解法
        // 变量s的每个位置
        // 判断以此为开始是否能够匹配
        // 匹配算法：按长度划分子字符串，字串匹配【hashtable】

        unordered_map<string, int> map;

        for(auto str: words)
        {
            map[str]++;
        }

        int len = words[0].length();

        vector<int> res;

        for(int i = 0; i < s.length() - words.size() * len + 1; i++)
        {
            // check
            unordered_map<string, int> newmap;

            int cnt = 0;
            while(i + (cnt + 1)* len <= s.length() && cnt < words.size())
            {
                string word = s.substr(i + (cnt) * len, len);
                // cout << "i=" << i << " " << word << endl; 

                if(map[word] - newmap[word] > 0)
                {
                    newmap[word]++;
                    cnt++;
                }
                else
                {
                    break;
                }
            }

            if(cnt == words.size())
            {
                res.push_back(i);
            }

        }
        
        return res;

        
    }
};
// @lc code=end

