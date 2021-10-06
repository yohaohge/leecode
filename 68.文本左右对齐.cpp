/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
public:
    string fullJustifyOneline(vector<string>& words, int maxWidth, int total)
    {
        if(words.size() == 0)
            return string(maxWidth, ' ');
        if(words.size() == 1)
            return words[0] + string(maxWidth - total, ' ');
        
        int spacecnt = (maxWidth - total) / (words.size() - 1);
        int remmain = (maxWidth - total) % (words.size() - 1);

        string res;
        for(int i = 0; i < words.size(); ++i)
        {
            res += words[i];
            if(i != words.size() - 1) // coner case
            {
                res += string(spacecnt, ' ');
                if(i < remmain)
                {
                    res += " ";
                }
            }
        }

        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> tmp;

        int iTotal = 0;
        for(int i = 0; i < words.size(); ++i)
        {
            if(iTotal + tmp.size() + words[i].length() > maxWidth)
            {
                res.push_back(fullJustifyOneline(tmp, maxWidth, iTotal));
                tmp.clear();
                iTotal = 0;
            }
            tmp.push_back(words[i]);
            iTotal += words[i].length();
        }

        // coner case
        string str;
        for(int i = 0; i < tmp.size(); i++)
        {
            if(i > 0)
                str += " ";
            str += tmp[i];
        }

        str += string(maxWidth - str.length(), ' ');
        res.push_back(str);
        return res;
    }
};
// @lc code=end

