/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        while(numRows --)
        {
            if(ans.size() == 0)
            {
                tmp.push_back(1);
            }
            else
            {
                tmp.push_back(1); // 头
                for(int i = 1; i < ans.back().size(); i++)
                {
                    tmp.push_back(ans.back()[i] + ans.back()[i-1]);
                }
                tmp.push_back(1); // 尾
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
// @lc code=end

