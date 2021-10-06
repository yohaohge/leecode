/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string result = "";
        //the size of a cycle(period)
        for(int i = 0; i < numRows; ++i)
        {
            for(int j = i; j < s.length(); j += 2*(numRows-1))
            {
                result += s[j];
                if(i != 0 && i != numRows -1)
                {
                    int index = j + 2*(numRows-1) - i -i;
                    if(index < s.length())
                    {
                        result += s[index];
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

