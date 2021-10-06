/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */


// 2021 06 01 花费30min+时间处理

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cntMap;
        unordered_map<char, int> curMap;
        for(auto ch: t)
        {
            cntMap[ch]++;
        }

        int left = 0, right = 0;

        string res = "";

        int totolCnt = cntMap.size();
        int curCnt = 0;
        
        while(right < s.length())
        {
            // 先扩大
            char ch = s[right];
            curMap[ch]++;
            right++;
            if(cntMap.find(ch) != cntMap.end() && curMap[ch] == cntMap[ch])
            {
                curCnt++;
            }

            // 后缩小
            if(curCnt >= totolCnt)
            {
                while(cntMap.find(s[left]) == cntMap.end() || curMap[s[left]] > cntMap[s[left]])
                {
                    char ch = s[left];
                    curMap[ch]--;
                    left++;
                }

                if(right - left < res.length()||res.length() == 0)
                {
                    res = s.substr(left, right - left);
                }
                char ch = s[left];
                curMap[s[left]]--;
                    left++;
                if(curMap[ch] < cntMap[ch])
                    curCnt--;
            }

        }

        return res;
    }
};
// @lc code=end

