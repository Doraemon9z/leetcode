/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() >> 1; i++, j--) {
            // 通过位运算
            // s[i] ^= s[j];
            // s[j] ^= s[i];
            // s[i] ^= s[j];

            // 通过库函数
            swap(s[i],s[j]);
        }
        
    }
};
// @lc code=end

