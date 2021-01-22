/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int iLeft = 0, iRight = 0;
        unordered_map<char, int> mapNeed, mapWindow;
        for(char c: t) mapNeed[c] ++;

        int valid = 0;
        int iStart = 0, iLen = INT_MAX;
        while(iRight < s.length())
        {
            char c = s[iRight];
            iRight++; // 开区间

            if(mapNeed.count(c)) 
            {
                mapWindow[c]++;
                if(mapWindow[c] == mapNeed[c]) 
                {
                    valid++;
                }
            }
            
            if(valid == mapNeed.size() )
            {
                while(valid == mapNeed.size() )
                {
                    if(iRight - iLeft < iLen)
                    {
                        iStart = iLeft;
                        iLen = iRight - iLeft;
                    }

                    char d = s[iLeft];
                    iLeft ++;

                    if(mapNeed.count(d)) {
                        if(mapWindow[d] == mapNeed[d])
                        {
                            valid--;
                        }
                        mapWindow[d]--;
                    }
                }
            }
        }

        return iLen == INT_MAX ? "" : s.substr(iStart, iLen);
    }
};
// @lc code=end

