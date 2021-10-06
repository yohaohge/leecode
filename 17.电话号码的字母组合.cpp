/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    void dfs(string& digits, int index, string cur, vector<string>& res, unordered_map<char, string>& myMap)
    {
        if(index == digits.length())
        {
            res.push_back(cur);
            return ;
        }

        for(auto e:myMap[digits[index]])
            dfs(digits, index + 1, cur + e, res, myMap);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0)
            return res;
        unordered_map<char, string> myMap;
        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";
        dfs(digits, 0, "", res, myMap);
        return res;
    }
};
// @lc code=end

