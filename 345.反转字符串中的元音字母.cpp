/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set;
        set.insert('a');
        set.insert('e');
        set.insert('i');
        set.insert('o');
        set.insert('u');
        set.insert('A');
        set.insert('E');
        set.insert('I');
        set.insert('O');
        set.insert('U');

        int left = 0, right = s.length() -1;
        while(left < right)
        {
            if(set.find(s[left]) == set.end())
                left++;
            else if(set.find(s[right]) == set.end())
                right--;
            else
            {
                swap(s[left], s[right]);
                left++; right--;
            }
        }

        return s;
    }
};
// @lc code=end

