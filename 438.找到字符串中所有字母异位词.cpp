/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int iLeft = 0, iRight = 0;
        vector<int> vecRes;

        unordered_map<char, int> mapNeed, mapWindow;
        for(char c: p) mapNeed[c]++;
        int iValid = 0;

        while(iRight < s.length())
        {
            char c = s[iRight];
            iRight ++;
            if(mapNeed.count(c))
            {
                mapWindow[c] ++;
                if(mapWindow[c] == mapNeed[c])
                {
                    iValid++;
                }
            }

            if(iValid == mapNeed.size())
            {
                while(iValid == mapNeed.size())
                {
                    // 条件修改
                    if(iRight - iLeft == p.length())
                        vecRes.push_back(iLeft);
                    char d = s[iLeft];
                    iLeft ++;

                    if(mapWindow.count(d)){
                        if(mapWindow[d] == mapNeed[d])
                        {
                            iValid--;
                        }
                        mapWindow[d] --;
                    }
                }
            }
        }

        return vecRes;
    
    }
};
// @lc code=end

