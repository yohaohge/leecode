/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> out = {0};
        for(int i = 0; i < n; i++) 
        {
            for(int j = out.size()-1; j >= 0; j--) 
            {
                out.push_back(out[j] + pow(2, i));
            }
        }
        return out;

    }
};
// @lc code=end

