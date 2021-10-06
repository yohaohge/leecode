/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        if(num <= 0)
            return "";
         
        // if(num >= 1000)
        //     return string("M") + intToRoman(num - 1000);
        // if(num >= 900)
        //     return string("CM") + intToRoman(num - 900);
        // if(num >= 500)
        //     return string("D") + intToRoman(num - 500);
        // if(num >= 400)
        //     return string("CD") + intToRoman(num - 400);
        // if(num >= 100)
        //     return string ("C") + intToRoman(num - 100);
        //  if(num >= 90)
        //     return string("XC") + intToRoman(num - 90);
        // if(num >= 50)
        //     return string("L") + intToRoman(num - 50);
        // if(num >= 40)
        //     return string("XL") + intToRoman(num - 40);
        // if(num >= 10)
        //     return string("X") + intToRoman(num - 10);
        // if(num >= 9)
        //     return string("IX") + intToRoman(num - 9);
        // if(num >= 5)
        //     return string("V") + intToRoman(num - 5);
        // if(num >= 4)
        //     return string("IV") + intToRoman(num - 4);
        
        // return string("I") + intToRoman(num - 1);


        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < 13; i++)
        {
            if(nums[i] <= num)
                return roman[i] +  intToRoman(num - nums[i]);
        }

        return "";
    }
};
// @lc code=end

