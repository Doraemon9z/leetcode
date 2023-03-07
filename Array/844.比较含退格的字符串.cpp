/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    ++skipS, --i;
                } else if (skipS > 0) {
                    --skipS, --i;
                } else {
                    break;
                }
            }
        }
        while (j >= 0) {
            if (t[j])
        }


        // 重构字符串
        // return build(s) == build(t);
    }

    // 重构字符串
    /* string build(string str) {J
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    } */
};
// @lc code=end

