/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int iLeft = 0, iRight = 0;
        unordered_map<char, int> mapWindow;
        int iLen = 0;

        while(iRight < s.length())
        {
            char c = s[iRight];
            iRight++;

            mapWindow[c]++;   

            char d = s[iLeft];

            if(mapWindow[c] > 1)
            {
                while(mapWindow[c] > 1)
                {
                    char d = s[iLeft];
                    iLeft++;
                    mapWindow[d]--;
                }
            }

            iLen = max(iLen, iRight - iLeft);
        }

        return iLen;
    }
};
// @lc code=end

