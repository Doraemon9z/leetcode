/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start// 暴力匹配
class Solution {
public:
    int strStr(string haystack, string needle) {   
        // KMP算法
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                ++j;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                ++j;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;        
        
        
        // 暴力匹配
        /* int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; ++i) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1; */
             

    }
};
// @lc code=end

