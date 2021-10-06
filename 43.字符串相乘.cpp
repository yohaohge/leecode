/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string add(string num1, string num2)
    {
        string res = "";
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));

        int i = 0;
        int sum = 0;
        while(i < num1.size() && i < num2.size())
        {
            sum += num1[i] - '0' + num2[i] - '0';
            res = res + to_string(sum%10);
            sum /= 10;
            i++;
        }

        while(i < num1.size())
        {
            sum += num1[i] - '0';
            res = res + to_string(sum%10);
            sum /= 10;
            i++;
        }

        while(i < num2.size())
        {
            sum += num2[i] - '0';
            res = res + to_string(sum%10);
            sum /= 10;
            i++;
        }

        if(sum > 0)
            res = res + to_string(sum);
        reverse(begin(res), end(res));
        return res;
    }

    string multiply_one(string num1, char ch)
    {
        reverse(begin(num1), end(num1));
        string res;
        int mul = 0;
        for(int i = 0; i < num1.size(); i++)
        {
            mul += (num1[i] - '0') * (ch - '0');
            res = res + to_string(mul%10);
            mul /= 10;
        }

        if(mul > 0)
            res = res + to_string(mul);
        reverse(begin(res), end(res));
        return res;
    }

    string multiply(string num1, string num2) {
        if(num1.length() < num2.length())
            return multiply(num2, num1);
        if(num1 == "0" || num2 == "0")
            return "0";
            
        string result;
        for(int i = num2.length() - 1; i >= 0; i--)
        {
            result = add(result, multiply_one(num1, num2[i]));
            num1 = num1 + "0";
        }
        return result;
    }
};
// @lc code=end

