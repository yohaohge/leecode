/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> vecMap;
        for(auto str:strs)
        {
            map<char, int> chMap;
            for(auto ch:str)
            {
                chMap[ch]++;
            }

            string key;
            for(auto item:chMap)
            {
                key = key+to_string(item.second)+to_string(item.first);
            }
            vecMap[key].push_back(str);
    
        }

        vector<vector<string>> res;

        for(auto v:vecMap)
            res.push_back(v.second);
        
        return res;
    }
};
// @lc code=end

