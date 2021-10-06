/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // int iLeft = 0,  iRight =0;
        // unordered_map<char, int> mapNeed, mapWindow;

        // for(char c: s1) mapNeed[c]++;

        // int iValid = 0;
        // while(iRight < s2.length())
        // {
        //     char c = s2[iRight];
        //     iRight ++;

        //     if(mapNeed.count(c))
        //     {
        //         mapWindow[c]++;
        //         if(mapWindow[c] == mapNeed[c] )
        //         {
        //             iValid++;
        //         }
        //     }

        
        //     if(iValid == mapNeed.size())
        //     {
        //         while(iValid == mapNeed.size())
        //         {
        //             if(iRight - iLeft == s1.length())
        //                 return true;
        //             char d = s2[iLeft];
        //             iLeft ++;

        //             if(mapWindow.count(d)) {
        //                 if(mapWindow[d] == mapNeed[d])
        //                 {
        //                     iValid --;
        //                 }
        //                 mapWindow[d] --;
        //             }
        //         }
        //     }

        // }

        unordered_map<char, int> cntMap;
        unordered_map<char, int> curMap;

        for(auto ch:s1)
            cntMap[ch]++;
        int size = cntMap.size();
        
        int cnt = 0;

        for(int i = 0, j = 0; i < s2.length(); i++)
        {
            char ch = s2[i];

            curMap[ch]++;

            // if(cntMap[ch] == 0)
            // {
            //     curMap.clear();
            //     j = i + 1;
            //     cnt = 0;
            //     continue;
            // }
            
            if(cntMap[ch] == curMap[ch])
            {
                cout << ch << " " << cntMap[ch] << endl;
                cnt++;
                if(cnt == size)
                    return true;
            }

            while(cntMap[ch] < curMap[ch])
            {
                
                if(cntMap[s2[j]] > 0 && curMap[s2[j]] == cntMap[s2[j]])
                    cnt--;
                curMap[s2[j++]]--;
            }

        }

        return false;
    }
};
// @lc code=end

